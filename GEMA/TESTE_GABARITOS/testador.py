import os
import subprocess

def verificar_gabarito(diretorio_base, executavel):
    # Lista todas as pastas numeradas de 1 a N
    pastas = [pasta for pasta in os.listdir(diretorio_base) if os.path.isdir(os.path.join(diretorio_base, pasta)) and pasta.isdigit()]

    for pasta in sorted(pastas, key=int):
        caminho_pasta = os.path.join(diretorio_base, pasta)
        arquivos_in = [arquivo for arquivo in os.listdir(caminho_pasta) if arquivo.endswith('.in')]

        for arquivo_in in sorted(arquivos_in):
            numero = arquivo_in.split('.')[0]
            caminho_arquivo_in = os.path.join(caminho_pasta, arquivo_in)
            caminho_arquivo_sol = os.path.join(caminho_pasta, f"{numero}.sol")

            print(f"Executando teste {numero} na pasta {pasta}...")
            print(f"Caminho do arquivo .in: {caminho_arquivo_in}")
            print(f"Caminho do arquivo .sol: {caminho_arquivo_sol}")

            # Executa o programa com o arquivo .in e captura a saída
            resultado = subprocess.run([executavel], input=open(caminho_arquivo_in, 'rb').read(), capture_output=True, text=True)
            saida = resultado.stdout.strip()

            # Verifica se houve erro na execução
            if resultado.returncode != 0:
                print(f"Erro ao executar o programa: {resultado.stderr}")
                continue

            print(f"Saída obtida: {saida}")

            # Lê o arquivo .sol esperado
            with open(caminho_arquivo_sol, 'r') as f:
                solucao_esperada = f.read().strip()

            # Compara a saída do programa com a solução esperada
            if saida == solucao_esperada:
                print(f"[Pasta {pasta}] Teste {numero}: OK")
            else:
                print(f"[Pasta {pasta}] Teste {numero}: FALHOU")
                print(f"Esperado: {solucao_esperada}")
                print(f"Obtido:   {saida}")

# Exemplo de uso
diretorio_base = '.'
executavel = './Viagem_OBI2022.exe'
verificar_gabarito(diretorio_base, executavel)
