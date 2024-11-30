#include <stdio.h>
#include <string.h>
#define MAX 100
#define Bimestremax 4
struct Escola
{
    char nomeAluno[MAX];
    float Media_sala;
    float Media;
    float Notas[Bimestremax];
    char Matricula[MAX];
};

void registro(struct Escola Registr[], int *numalunos);
void Procurar_Aluno(struct Escola Registr[], int numalunos);
void Media_Sala(struct Escola Registr[], int numalunos);
void maior_nota(struct Escola Registr[], int numalunos);

int main(){
    int opcao, numalunos=0;
    struct Escola Registr[MAX];
    do
    {
    printf("------------------MENU------------------\n");
    printf("[1]Registrar aluno:\n[2]Procurar Aluno:\n[3]Calcular media da turma:\n[4]Mostrar maior nota da turma:\n[5]Sair:\n------------------------------------\n:");
        scanf(" %d", &opcao);
        switch (opcao)
        {
        case 1:
            system("cls");
            registro(Registr, &numalunos);
            break;
        case 2:
            system("cls");
            Procurar_Aluno(Registr, numalunos);
            break;
        case 3:
            system("cls");
            Media_Sala(Registr, numalunos);
            break;
        case 4:
            system("cls");
            maior_nota(Registr, numalunos);
            break;
        case 5:
            system("cls");
            printf("Saindo....");
            break;        
        default:
            printf("coloque uma das opções acima:\n");
            break;
        }
    } while (opcao!=5);
    return 0;
}

void registro(struct Escola Registr[], int *numalunos){
    char resp='n'; int contaregistro=0, i; float nota, total=0;
    if (contaregistro>MAX)
    {
        printf("Chegou ao maximo de alunos registrados\n");
        return;
    }
    
    do
    {
        i=0;
        system("cls");
        printf("------------------REGISTRO------------------\n");
        printf("Numero da matricula: ");
        getchar();
        fgets(Registr[*numalunos].Matricula, MAX, stdin);
        Registr[*numalunos].Matricula[strcspn(Registr[*numalunos].Matricula, "\n")] = '\0';

        printf("Nome do Aluno: ");
        fgets(Registr[*numalunos].nomeAluno, MAX, stdin);
        Registr[*numalunos].nomeAluno[strcspn(Registr[*numalunos].nomeAluno, "\n")] = '\0';
        
        
        while (1) //Usei while(1), pq tem o if, e achava que if com for ia ser chato e complicado dms, dai usei while
        {
            printf("Adicione nota %d bimestre: ", i+1);
            scanf("%f", &nota);
            if (nota>=0 && nota<=10)
            {
                Registr[*numalunos].Notas[i]= nota;
                i++;
                total+=nota;
                if (i==Bimestremax)
                {
                    break;
                }
                
            }
            else
            {
                printf("nota invalida\n");
            }
        }

        (*numalunos)++;
        
        contaregistro++;    

        printf("Adicionar mais Alunos?(s/n): ");
        getchar();  
        scanf(" %c", &resp);
        getchar();
    } while (resp != 'n');
}

void Procurar_Aluno(struct Escola Registr[], int numalunos){
        char NumMatricula[MAX]; int encontrado=0; float total;
        printf("Numero da Matricula:");
        getchar();
        fgets(NumMatricula, MAX, stdin);
        NumMatricula[strcspn(NumMatricula, "\n")] = '\0';
        for (int i = 0; i < numalunos; i++)
        {
        total=0;
            if (strcmp(Registr[i].Matricula, NumMatricula) == 0)
            {
                printf("\n");
                printf("------------------ALUNO ENCONTRADO------------------\n");
                printf("Matricula: %s\n", Registr[i].Matricula);
                printf("Nome: %s\n", Registr[i].nomeAluno);
                
                for (int j = 0; j < Bimestremax; j++)
                {
                    printf("%d Bimeste  Notas: %.1f\n", j+1,Registr[i].Notas[j]);
                    total += Registr[i].Notas[j];
                }

                Registr[i].Media = total / Bimestremax;
                printf("Media: %.1f\n", Registr[i].Media);
                printf("----------------------------------------------------\n");
                encontrado=1;
                break;
            }
        }
    if (!encontrado)
    {
        printf("Nenhum aluno encontrado\n");
        return;
    }
}

void Media_Sala(struct Escola Registr[], int numalunos){
    float Notas=0, contalunos=0;
    for (int i = 0; i < numalunos; i++)
    {
        for (int j = 0; j < Bimestremax; j++)
        {
            Notas += Registr[i].Notas[j];
            contalunos+=1;
        }
    }
    printf("Media sala: %.1f\n", Notas/contalunos);
}

void maior_nota(struct Escola Registr[], int numalunos){
    float Maiornota=0; char Aluno[MAX];
    for (int i = 0; i < numalunos; i++)
    {
        for (int j = 0; j < Bimestremax; j++)
        {
            if (Maiornota<Registr[i].Notas[j])
            {
                Maiornota=Registr[i].Notas[j];
                strcpy(Aluno, Registr[i].nomeAluno);
            }
        }
    }
    printf("------------------MAIOR NOTA------------------\n");
    printf("Aluno/a: %s\n", Aluno);
    printf("Maior nota da sala: %.1f\n", Maiornota);
    printf("----------------------------------------------------\n");
}