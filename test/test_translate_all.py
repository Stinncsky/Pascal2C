import subprocess
import os
import sys

def run_test(exe):
    print(f"Running {exe} ...", end=' ')
    try:
        result = subprocess.run([exe], capture_output=True, text=True, timeout=10)
        if result.returncode == 0:
            print("PASS")
        else:
            print("FAIL")
            print(result.stdout)
            print(result.stderr)
    except Exception as e:
        print(f"ERROR: {e}")

def main():
    # 测试可执行文件名列表（假设已编译为同名exe）
    test_names = [
        'test_translate_const',
        'test_translate_var',
        'test_translate_final',
        'test_translate_factor',
        'test_translate_term',
        'test_translate_expression',
        'test_translate_statement',
        'test_translate_subprogram',
        'test_translate_program',
    ]
    test_dir = os.path.dirname(os.path.abspath(__file__))
    for name in test_names:
        exe = os.path.join(test_dir, name + ('.exe' if os.name == 'nt' else ''))
        src = os.path.join(test_dir, name + '.cc')
        # 如果可执行文件不存在，尝试编译
        if not os.path.exists(exe):
            if os.path.exists(src):
                print(f"[INFO] {exe} not found. Compiling {src} ...")
                compile_cmd = ['g++', src, '-o', exe]
                try:
                    result = subprocess.run(compile_cmd, capture_output=True, text=True, timeout=20)
                    if result.returncode != 0:
                        print(f"[COMPILE FAIL] {src}")
                        print(result.stdout)
                        print(result.stderr)
                        continue
                except Exception as e:
                    print(f"[COMPILE ERROR] {e}")
                    continue
            else:
                print(f"[SKIP] {exe} and {src} not found.")
                continue
        run_test(exe)

if __name__ == '__main__':
    main()
