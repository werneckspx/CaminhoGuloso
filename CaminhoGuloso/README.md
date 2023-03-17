# Caminho Guloso: Implementação em C++

<div style="display: inline-block;">
<img align="center" height="20px" width="60px" src="https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/> 
<img align="center" height="20px" width="80px" src="https://img.shields.io/badge/Made%20for-VSCode-1f425f.svg"/> 
</a> 
</div>

# Problema Proposto
<p align="justify">
  Utilizando o processo de caminhamento guloso, nesse projeto o objetivo e caminhar por matrizes NxN, passadas como entrada, iniciando pela posicao 0x0. O caminho passado sera o que apresentar o maior valor entre as opcoes em relacao a posicao atual: <br>
  - Caminhar a direita. <br>
  - Caminhar a esquerda. <br>
  - Caminhar para baixo. <br>
  - Caminhar na diagonal direita e esquerda para baixo. <br>
  Atraves dessas regras, o objetivo do programa apresentado e chegar na posicao NxN passando pelos maiores valores.
</p>

# Logica

<p align="justify">
    Para a criacao da matriz foi utilizado um vector de vector inteiro.
  ```c++
    vector<vector<int>> mat;
  ```
</p>


# Compilação e Execução

Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contatos

<div style="display: inline-block;">
<a href="https://t.me/michelpires369">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/michelpiressilva/">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>
