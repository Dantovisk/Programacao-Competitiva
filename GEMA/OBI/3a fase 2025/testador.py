import os
import subprocess
import sys
import difflib

# Configurações
PROBLEM_DIR = '2024f3p2_burocracia'
EXECUTABLE = './burocracia'
SOURCE = 'burocracia.cpp'

# Compila se necessário
def compile_if_needed():
    if not os.path.isfile(EXECUTABLE.strip('./')):
        print(f"Compilando {SOURCE}...")
        ret = subprocess.run(['g++', '-std=c++17', '-O2', '-o', EXECUTABLE.strip('./'), SOURCE])
        if ret.returncode != 0:
            print('Falha na compilação.', file=sys.stderr)
            sys.exit(1)

def testar_caso(sub, base):
    subdir = os.path.join(PROBLEM_DIR, sub)
    infile = os.path.join(subdir, f"{base}.in")
    solfile = os.path.join(subdir, f"{base}.sol")

    if not os.path.isfile(infile) or not os.path.isfile(solfile):
        print(f"[ERROR] Arquivo de entrada ou solução não encontrado para {sub}/{base}")
        return

    with open(infile, 'r') as fin:
        proc = subprocess.run([EXECUTABLE], stdin=fin, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    out = proc.stdout.strip().splitlines()
    with open(solfile, 'r') as fsol:
        expected = fsol.read().strip().splitlines()

    if out == expected:
        print(f"[PASS]  Caso {sub}/{base}")
    else:
        print(f"[FAIL]  Caso {sub}/{base}")
        print("  Saída obtida:")
        for line in out[:5]: print(f"    {line}")
        print("  Esperado:")
        for line in expected[:5]: print(f"    {line}")
        diff = difflib.unified_diff(expected, out, fromfile='esperado', tofile='obtido', lineterm='')
        print('\n'.join('    ' + l for l in diff))

# Executa e compara
def run_tests():
    total = 0
    passed = 0
    print('Iniciando testes...')
    # percorre subpastas numeradas
    for sub in sorted(os.listdir(PROBLEM_DIR), key=lambda x: int(x) if x.isdigit() else x):
        subdir = os.path.join(PROBLEM_DIR, sub)
        if not os.path.isdir(subdir):
            continue
        # para cada arquivo .in no diretório
        for fname in sorted(os.listdir(subdir)):
            if not fname.endswith('.in'):
                continue
            base = fname[:-3]  # '1' de '1.in'
            infile = os.path.join(subdir, f"{base}.in")
            solfile = os.path.join(subdir, f"{base}.sol")
            if not os.path.isfile(solfile):
                print(f"[WARNING] Solução esperada não encontrada: {solfile}")
                continue

            # executa o programa
            with open(infile, 'r') as fin:
                proc = subprocess.run([EXECUTABLE], stdin=fin, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
            out = proc.stdout.strip().splitlines()
            with open(solfile, 'r') as fsol:
                expected = fsol.read().strip().splitlines()

            # compara
            total += 1
            if out == expected:
                print(f"[PASS]  Caso {sub}/{base}")
                passed += 1
            else:
                print(f"[FAIL]  Caso {sub}/{base}")
                #print("  Entrada:")
                #for line in out[:5]: print(f"    {line}")
                #print("  Esperado:")
                #for line in expected[:5]: print(f"    {line}")
                # opcional: exibir diff completo
                #import difflib
                #diff = difflib.unified_diff(expected, out, fromfile='esperado', tofile='obtido', lineterm='')
                #print('\n'.join('    ' + l for l in diff))
                #print()
    print('-' * 40)
    print(f'Total: {passed}/{total} casos passaram.')

if __name__ == '__main__':
    compile_if_needed()
    if len(sys.argv) == 2 and '/' in sys.argv[1]:
        pasta, caso = sys.argv[1].split('/')
        testar_caso(pasta, caso)
    else:
        run_tests()

