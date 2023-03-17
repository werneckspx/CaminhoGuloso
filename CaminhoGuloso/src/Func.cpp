#include "Func.hpp"

void ReadMat(){

    vector<vector<int>> mat;
    string filename("dataset/input.data");
    ifstream input_file(filename,ios::in);
    string line;
    vector<int> n;
    int tam,somaTotal=0;

    //verificando se o arq pode ser aberto.
    if (!input_file.is_open()) {
        cout << "Nao foi possivel abrir o arquivo"
            << filename << " " << endl;
    }
    //criando a string para a tokenizacao
    string num;
    //criando um contador para pular a primeira linha
    int cont=0;
    while (!input_file.eof())
    {
        while (getline(input_file, line,'\n')){
            // criando o operador de extracao(pula espaco em branco por padrao)
            istringstream ln(line);
            if (cont==0)
            {
                tam=atoi(line.c_str());
                cont++;
                continue;    
            }else if (line.size()>1)
            {
                //tokenizacao da string line convertendo a string num para int
                while (ln >> num) {
                    n.push_back(atoi(num.c_str()));
                }
                //colocando os valores na matriz
                mat.push_back(n);
                //limpando os vectors
                line.clear();
                n.clear();
            }//else para o desenvolvimento do programa chamando as funcoes de caminha para a matriz, clear no mat no final
            else{
                cout<<endl;
                Verificando(mat,0,0,tam,&somaTotal);
                Imprimindo(mat);
                cout<<endl;
                mat.clear();
                
            }
        } 
    }
    cout<<"Soma total: "<<somaTotal<<endl;
    input_file.close();
}

void Imprimindo(vector<vector<int>>mat){
    
    for (int i = 0; i < mat.size(); i++)
    {
        for (int j = 0; j < mat[i].size(); j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Verificando(vector<vector<int>>mat, int linha, int coluna,int tam, int *somaTotal){

    vector<int> comparar;
    int soma=0;
    int aux=0;
    soma=soma+mat[linha][coluna];
    mat[linha][coluna]=0;

    cout<<"CAMINHO PERCORRIDO"<<endl;
    do
    {
        if (linha==tam-1)
        {
            aux=0;
            comparar.push_back(mat[linha][coluna+1]);
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
        }else if (coluna==0)
        {
            aux=0;
            comparar.push_back(mat[linha+1][coluna+1]);
            comparar.push_back(mat[linha+1][coluna]);
            comparar.push_back(mat[linha][coluna+1]);
            sort(comparar.begin(), comparar.end(), greater<>());

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
        }else if (coluna==tam-1)
        {
            aux=0;
            comparar.push_back(mat[linha+1][coluna]);
            comparar.push_back(mat[linha][coluna-1]);
            comparar.push_back(mat[linha+1][coluna-1]);
            sort(comparar.begin(), comparar.end(), greater<>());

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
        }else{
            aux=0;
            comparar.push_back(mat[linha+1][coluna+1]);
            comparar.push_back(mat[linha+1][coluna-1]);
            comparar.push_back(mat[linha+1][coluna]);
            comparar.push_back(mat[linha][coluna+1]);
            comparar.push_back(mat[linha][coluna-1]);
            //Comparando o maior usando a funcao SORT
            sort(comparar.begin(), comparar.end(), greater<>());

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
        }
        if (linha==tam-1 && coluna==tam-1)
        {
            break;
        }
    } while (linha<tam && coluna<tam);
    cout<<endl;
    cout<<"soma: "<<soma<<endl;
    *somaTotal= *somaTotal+soma;
    Imprimindo(mat);
    
}