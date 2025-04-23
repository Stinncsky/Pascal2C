from flask import Flask, request, jsonify
from flask_cors import CORS
import subprocess
import os

app = Flask(__name__)
CORS(app)  # 允许所有域跨域访问

@app.route('/', methods=['POST'])
def handle_translation():
    try:
        data = request.get_json()
        
        text = data.get('text', '')
        source_lang = data.get('source_lang', '')
        target_lang = data.get('target_lang', '')

        if not (source_lang == 'pas'):
            return jsonify({
                "error": "当前版本仅支持 pascal 语言作为输入语言"
            }), 418
        if not (target_lang == 'c' or target_lang == 'asm'):
            return jsonify({
                "error": "当前版本仅支持 c 语言或汇编语言作为输出语言"
            }), 418

        with open("../http.pas", "w", encoding="utf-8") as file:
            file.write(text)
        file.close()

        # 若找不到 main.exe，则执行编译
        if not os.path.exists("../main.exe"):
            compile_args = ["g++", "-o", "../main.exe", "../main.cc"]
            result = subprocess.run(compile_args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            if result.returncode != 0:
                print(result.returncode, result.stderr.strip())
                return jsonify({
                    "error": "编译失败",
                    "details": result.stderr.strip()
                }), 500

        exe_path = "../main.exe"
        args = [exe_path, "-i", "../http.pas"]
        translated_text = ""
        # 执行编译后的程序并传入参数
        result = subprocess.run(args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if result.returncode == 0 and result.stderr.strip() == "":
            with open("../http.c", "r", encoding="utf-8") as file:
                translated_text = file.read()
            file.close()
            if target_lang == 'c':
                os.remove("../http.c")
            os.remove("../http.pas")
        elif result.returncode == 0:
            print(result.returncode, result.stderr.strip())
            if os.path.exists("../http.c"):
                with open("../http.c", "r", encoding="utf-8") as file:
                    translated_text = file.read()
                file.close()
                os.remove("../http.c")
            if os.path.exists("../http.pas"):
                os.remove("../http.pas")
            if target_lang == 'c':
                return jsonify({
                    "result": translated_text,
                    "error": "翻译错误",
                    "details": result.stderr.strip()
                }), 200
            else:
                return jsonify({
                    "error": "翻译错误",
                    "details": result.stderr.strip() + "\n无法安全生成汇编代码"
                }), 200
        else:
            if os.path.exists("../http.pas"):
                os.remove("../http.pas")
            errdetail = "Runtime Error: Unexpected Exit With Code " + str(result.returncode)
            if result.stderr:
                errdetail += "\n" + result.stderr.strip()
            return jsonify({
                "error": "翻译失败",
                "details": errdetail
            }), 200
        
        if target_lang == 'c':
            return jsonify({
                "result": translated_text
            }), 200
        elif target_lang == 'asm':
            # 调用gcc编译器生成汇编代码
            try:
                compile_args = ["gcc", "-S", "-o", "../http.s", "../http.c"]
                result = subprocess.run(compile_args, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
                if result.returncode != 0:
                    print(result.returncode, result.stderr.strip())
                    return jsonify({
                        "error": "编译失败",
                        "details": result.stderr.strip()
                    }), 500
                with open("../http.s", "r", encoding="utf-8") as file:
                    translated_text = file.read()
                file.close()
                os.remove("../http.c")
                os.remove("../http.s")
                return jsonify({
                    "result": translated_text
                }), 200
            except Exception as e:
                return jsonify({
                    "error": "生成汇编代码失败",
                    "details": str(e)
                }), 500

    except Exception as e:
        return jsonify({
            "error": str(e)
        }), 500

if __name__ == '__main__':
    app.run(port=10043, debug=True)