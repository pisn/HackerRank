#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x,y;
};

int getDifference(int **A,int **B){
    int i,j,m=0;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            m+=abs(A[i][j]-B[i][j]);
        }
    }
    return m;
}

int getNextAlgarism(int *alg,int atual){ //Vai ter que ter fila sim
    for(int i=atual+1;i<10;i++){
        if(alg[i] == 0)
            return i;
    }
    return -1;
}

int checkMatrix(int **tab){
    int i,j,sumRows=-1,sumColumns=-1,sr,sc;

    for(i=0;i<3;i++){
        sc=0;
        sr=0;

        for(j=0;j<3;j++){
            sr+=tab[i][j]; //Somando linha e coluna ao mesmo tempo
            sc+=tab[j][i];
            
            if(tab[i][j] == 0) //Tabela esta incompleta
                return 0;
        }

        if(sumRows == -1) //Primeira inicializacao de sums
            sumRows = sr;
        if(sumColumns == -1)
            sumColumns = sc;

        if(sumRows != -1 && sumRows != sr) //Soma nao bate com linha anterior
            return 0;

        if(sumColumns != -1 && sumColumns != sc) //Soma nao bate com coluna anterior
            return 0;

        if(sumColumns != sumRows)
            return 0;
    }

    sc=0;
    sr=0;
    for(i=0;i<3;i++){

        sc+=tab[i][i];
        sr+=tab[i][2-i];//Somando diagonais
    }
    if(sc!= sr || sc!=sumColumns)
        return 0;

    return 1;

}


int formingMagicSquare(int **A) {
    // Complete this function
    stack <Point*> sp;
    int *alg;
    Point *p;    
    int i,j,q,ex=0,m=1000;

    int **tab = (int**)malloc(sizeof(int*)*3);
    for(int i=0;i<3;i++)
        tab[i] = (int*)malloc(sizeof(int)*3);
    


    alg = new int[10];
    for(i=1;i<=9;i++)
        alg[i] = 1; //Todos algarismos usados
    
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            tab[i][j] = j + 3*i + 1; //formando primeira tabela

            p = new Point(); //Inicializando pontos
            p->x = i;
            p->y = j;
            sp.push(p);
        }
    }    
    
    while(!sp.empty()){
        p = sp.top();
        sp.pop(); //Desfaz ultima decisao
        alg[tab[p->x][p->y]] = 0;


        q= getNextAlgarism(alg,tab[p->x][p->y]); //Ação desfeita, troca por outro numero MAIOR
        tab[p->x][p->y] = 0; 
        while(q != -1){//Enquanto tiver algarismo pra colocar no tabuleiro coloca
            for(i=0;i<3 && q!=-1;i++){
                for(j=0;j<3 && q!= -1;j++){
                    if(tab[i][j]==0){ //Achou lugar vazio
                        alg[q] = 1;
                        tab[i][j] = q;

                        p = new Point();
                        p->x = i;
                        p->y = j;
                        sp.push(p);
                        
                        
                        q= getNextAlgarism(alg,0); //Nao estou desfazendo nenhuma acao, pode pegar qualquer um
                    }   
                }
            }            
        }


        if(checkMatrix(tab)){
            /*for(i=0;i<3;i++){
                for(j=0;j<3;j++){
                    cout << tab[i][j] << " ";
                }
                cout << endl;
            }
            cout << "---------------------" << endl;*/
            i = getDifference(tab,A);            
            if(i<m){
                m=i;
            }

        }
    }

    return m;
}



int main() {
    int **A = (int**)malloc(sizeof(int*)*3);
    for(int i=0;i<3;i++)
        A[i] = (int*)malloc(sizeof(int)*3);

    for(int s_i = 0;s_i < 3;s_i++){
       for(int s_j = 0;s_j < 3;s_j++){
          cin >> A[s_i][s_j];
       }
    }
    int result = formingMagicSquare(A);
    cout << result << endl;
    return 0;
}
