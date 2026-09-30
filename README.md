# 🏦 BANCO DO EMPRESÁRIO

Sistema de Registro e Gestão de Contas Bancárias desenvolvido em **C++** para a disciplina **INF101 - Programação de Computadores I**, como parte da **Etapa 1 do trabalho**.

## 📚 Sobre o projeto

O **Banco do Empresário** é um sistema simples para cadastro e gerenciamento de contas bancárias.

O programa permite cadastrar até **5 contas**, consultar os dados de uma conta, verificar o saldo, alterar o tipo da conta e ativar ou desativar contas.

O projeto foi desenvolvido utilizando conceitos básicos de programação em C++, como **variáveis, vetores, estruturas condicionais, estruturas de repetição e switch**.

## ⚙️ Funcionalidades

O sistema possui as seguintes opções:

1. **Cadastrar conta**
   - Número da conta
   - Nome do titular
   - CPF
   - Tipo da conta
   - Saldo inicial

2. **Consultar conta**
   - Número
   - Titular
   - CPF
   - Tipo da conta
   - Saldo
   - Situação da conta

3. **Verificar saldo**
   - Exibe o saldo atual da conta.

4. **Alterar tipo da conta**
   - Corrente
   - Poupança

5. **Ativar/Desativar conta**
   - Permite alternar a situação da conta.

6. **Sair**
   - Encerra o sistema.

## ✅ Validações

O sistema realiza algumas validações básicas:

- O número da conta deve ser maior que zero.
- Não é permitido cadastrar duas contas com o mesmo número.
- O saldo inicial não pode ser negativo.
- O tipo da conta deve ser `1` (Corrente) ou `2` (Poupança).
- Operações que dependem de uma conta ativa verificam sua situação.

## 💻 Tecnologias utilizadas

- **C++**
- Biblioteca `iostream`
- Biblioteca `string`

## 🎓 Informações acadêmicas

**Disciplina:** INF101 - Programação de Computadores I  
**Trabalho:** Sistema de Registro e Gestão de Contas Bancárias — Etapa 1  
**Aluno:** Tayrone Michael Martins Abreu  
**Matrícula:** 2660  
**Instituição:** Centro Universitário de Viçosa — UNIVIÇOSA

## 🚀 Como executar

1. Clone este repositório ou baixe os arquivos.
2. Abra o código-fonte em uma IDE compatível com C++.
3. Compile o programa.
4. Execute o sistema pelo terminal.

## 📌 Observação

Este projeto corresponde à **Etapa 1** do trabalho, tendo como objetivo aplicar os conceitos iniciais de programação em C++.
