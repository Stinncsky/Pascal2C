import os
import subprocess

testinput_folder = "open_set"

if not os.path.exists(testinput_folder):
    print(f"错误: {testinput_folder}文件夹不存在。")
    exit(1)

pas_files = [f for f in os.listdir(testinput_folder) if f.endswith(".pas")]

if not pas_files:
    print(f"{testinput_folder}文件夹中没有找到.pas文件。")
    exit(0)

print(f"找到{len(pas_files)}个.pas文件需要处理。")

all_success = True
for pas_file in pas_files:
    input_file = os.path.join(testinput_folder, pas_file)
    print(f"正在处理...")

    try:
        result = subprocess.run(["main.exe", "-ii", input_file], 
                              capture_output=True, text=True, check=False)

        if result.returncode != 0 or (result.stderr and "error" in result.stderr.lower()):
            print(f"处理{input_file}时出错: returncode = {result.returncode}")
            print(result.stderr)
            print(result.stdout)
            all_success = False
            break
        else:
            print(f"成功处理 {input_file}")

            try:
                result = subprocess.run(["gcc", "-o", "output.exe", "output.c"],
                                  capture_output=True, text=True, check=False)
                if result.returncode != 0 or result.stderr:
                    print(f"编译output.c时出错: returncode = {result.returncode}")
                    print(result.stderr)
                    print(result.stdout)
                    all_success = False
                    break
                else:
                    print(f"成功编译output.c")
            except Exception as e:
                print(f"发生异常: {e}")
                all_success = False
                break
    except Exception as e:
        print(f"发生异常: {e}")
        all_success = False
        break

print("所有文件处理完成。")
if all_success:
    print("所有文件处理成功。")
else:
    print("有文件处理失败。")
