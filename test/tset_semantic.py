import subprocess
import sys
import os
# 可执行文件名（假设已编译为 test_semantic_error.exe）
exe = 'test_semantic_error.exe'
# 获取当前脚本所在目录
test_dir = os.path.dirname(os.path.abspath(__file__))
src = 'test_semantic_error.cc'
src = os.path.join(test_dir, src)
if not os.path.exists(exe):
    # 编译C源文件
    compile_cmd = ['g++', src, '-o', exe]
    try:
        compile_result = subprocess.run(compile_cmd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
        if compile_result.returncode != 0:
            print(f"[FAIL] 编译失败: {compile_result.stderr.strip()}")
            sys.exit(1)
    except Exception as e:
        print(f"[FAIL] 编译过程中发生异常: {e}")
        sys.exit(1)
exe = 'test_semantic_error.exe'
# 获取当前脚本所在目录
test_dir = os.path.dirname(os.path.abspath(__file__))
# 构建可执行文件的完整路径
exe = os.path.join(test_dir, exe)
try:
    result = subprocess.run(exe, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
except Exception as e:
    print(f"[FAIL] 无法运行可执行文件: {e}")
    sys.exit(1)

# 捕获标准错误输出
stderr_output = result.stderr.strip()

# 统计错误输出条数（以换行分割）
err_lines = [line for line in stderr_output.split('\n') if line.strip()]

EXPECTED_ERROR_COUNT = 7  # 预期语义错误数

if len(err_lines) >= EXPECTED_ERROR_COUNT:
    print(f"[PASS] 语义错误分析检测通过，捕获到 {len(err_lines)} 条错误输出。")
else:
    print(f"[FAIL] 语义错误分析检测未通过，仅捕获到 {len(err_lines)} 条错误输出。\n错误内容如下:\n{stderr_output}")
