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
  <img src="imgs/exemploMat.png" /><br/>

# Logica

A funcao princial ```ReadMat()``` e chamada no main, nesta funcao ocorrem todos os processos do programa, partindo da leitura do arquivo ```dataset/input.data``` ate a relizacao do processo de caminhamento guloso na matriz. <br>

Para a criacao da matriz foi utilizado um vector de vector inteiro.
  
  ```c++
    vector<vector<int>> mat;
  ```

Durante o processo de leitura do arquivo, ocorria o processo de tokenizacao das informacoes, e a passagem de string para int, passagem necessaria para a realizacao das acoes futuras do algoritmo. Estes processos que sao realizados caso o else do codigo abaixo seja requisitado, nele estao as funcoes: <br>```Verificando``` que recebe como parametro a matriz, a posicao inicial da linha e coluna, o tamanho da matriz e o endereco da variavel soma total.<br> ```Imprimindo``` que recebe como parametro a matriz.

```c++
while (!input_file.eof())
    {
        while (getline(input_file, line,'\n')){
            istringstream ln(line);
            if (cont==0)
            {
                tam=atoi(line.c_str());
                cont++;
                continue;    
            }else if (line.size()>1)
            {
                while (ln >> num) {
                    n.push_back(atoi(num.c_str()));
                }
                mat.push_back(n);
                line.clear();
                n.clear();
            }
            else{
                cout<<endl;
                Verificando(mat,0,0,tam,&somaTotal);
                Imprimindo(mat);
                cout<<endl;
                mat.clear();
                
            }
        } 
    }
```
A funcao  Verificando  parte do pressuposto de que o caminho a ser percorrido deve ser entre os maiores valores, entre as opcoes, que estao na matriz. Para isso foi feito um vector ```vector<int> comparar``` que recebe os valores das posicoes a serem verificadas. Estes valores sao ordenados em ordem descrescente pela funcao sort ```sort(comparar.begin(), comparar.end(), greater<>())```, atraves dessa ordenacao, o maior valor entre os possiveis e colocado na primeira posicao do vector.<br>
Sabendo disso, uma leitura por toda matriz e realizada, nesta leitura busca-se o valor que esta na primeira posicao do vector, porem e valido ressaltar que pode ser que existam dois valores iguais e isso causaria um problema na logica, por isso uma condicao de que, caso a linha da atual posicao seja menor que a linha da leitura da matriz, o algoritmo torna possivel o recebimento da posicao. Ao achar o valor recebe a posicao linha e coluna, a posicao anterior recebe 0 para que seja marcado uma posicao ja verificada e o algoritmo soma 1 a uma varival auxiliar, esta que foi criada para interromper o loop de leitura da matriz.
  ```c++
            aux=0;
            for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    if (comparar[0]==mat[i][j])
                    {
                        if (linha<=i)
                        {
                            linha=i;
                            coluna=j;
                            aux++;
                            cout<<i<<" "<<j<<" Valor: "<<mat[i][j]<<"."<<endl;
                            soma=soma+mat[i][j];
                            mat[i][j]=0;
                            break;
                        }
                    }
                }
                if (aux>0)
                {
                    break;
                }
            }
            comparar.clear();
  ```

 Todo este processo e feito enquanto a posicao linha coluna nao sao iguais a posicao NxN da matriz passada. <br>
 Em casos particulares, como:<br>
 1-Linha atual igual ultima linha da matriz.: <br>
 2-Coluna atual igual primeira coluna da matriz. <br>
 3- Coluna atual igual ultima coluna da matriz. <br>
 Foram realizadas acoes permitidas somente para a posicao que se ocupava, para que o algoritmo nao acessasse posicoes indesejadas. <br>

  Este processo acontece enquanto a arquivo nao termina sua leitura, ou seja, para cada matriz no arquivo lido, e chamado uma vez a funcao verificando e a funcao imprimindo.

 # Biblitecas 
<p>Para o funcionamento do programa, é necessário incluir as seguintes bibliotecas: 
<ul>
    <li><code>#include 'iostream'</code></li>
    <li><code>#include 'fstream'</code></li>
    <li><code>#include 'vector'</code></li>
    <li><code>#include 'string'</code></li>
    <li><code>#include 'stream'</code></li>
    <li><code>#include 'iterator'</code></li>
    <li><code>#include 'algorithm'</code></li>
</ul>

# Compilação e Execução

Esse pequeno exemplo possui um arquivo Makefile que realiza todo o procedimento de compilação e execução. Para tanto, temos as seguintes diretrizes de execução:


| Comando                |  Função                                                                                           |                     
| -----------------------| ------------------------------------------------------------------------------------------------- |
|  `make clean`          | Apaga a última compilação realizada contida na pasta build                                        |
|  `make`                | Executa a compilação do programa utilizando o gcc, e o resultado vai para a pasta build           |
|  `make run`            | Executa o programa da pasta build após a realização da compilação                                 |


# Contatos

<div style="display: inline-block;">
<a href="https://t.me/felipewom">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/Telegram-2CA5E0?style=for-the-badge&logo=telegram&logoColor=white"/> 
</a>

<a href="https://www.linkedin.com/in/felipe-werneck-93520a209">
<img align="center" height="20px" width="90px" src="https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white"/>
</a>

</div>

<p> </p>
