#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    double weight;   // ��������
    double revenue;   // ��������
} Cargo;

// ���崬���Ľṹ��
typedef struct {
    double capacity;    // ��������������
    double speed;      // ���������ٶ�
    double cost;       // ��������ɱ�
} Ship;
void counter(void);
void caidan(void);
void choice1(void);
void choice2(void);
void choice3(void);
void exit_system(void);
char kb_hit(void);
void pause(void);
void caidan_print(void);

//���к�����������ʾ���˵� 
void counter(void){
	system("cls");
	caidan();
}

//���˵����� 
void caidan(void){
	system("cls");
	caidan_print();
}

//��������ָ�� 
char kb_hit(void){
	while(1){
		if(kbhit()){
			char ch=getch();
			if(ch>='0'&&ch<='3'){
				return(ch);
			}
		}
	}
}

//���˵���ʾѡ�� 
void caidan_print(void){
	printf("\t\t--------------------\n");
    printf("\t\t�̴�����װ�ط���ϵͳ\n");
    printf("\t\t--------------------\n");
    printf("\t\t1. �������\n");
    printf("\t\t2. ��������\n");
    printf("\t\t3. �˳�\n");
    printf("\t\t--------------------\n");
    printf("\t\t��ѡ���������1-3����");
}

//��1����ʾ���� 
void inputParameters(Cargo *cargo, Ship *ship) {
	system("cls"); 
	printf("\n\n\n\n");
    printf("\n\t���������������");
    scanf("%lf", &cargo->weight);
    printf("\n\t�������������");
    scanf("%lf", &cargo->revenue);
    printf("\n\t�����봬��������������");
    scanf("%lf", &ship->capacity);
    printf("\n\t�����봬�������ٶȣ�");
    scanf("%lf", &ship->speed);
    printf("\n\t�����봬������ɱ���");
    scanf("%lf", &ship->cost);
}

double calculateMaxProfit(Cargo cargo, Ship ship) {
    double totalCargoWeight = 0.0;
    double totalRevenue = 0.0;
    double remainingCapacity = ship.capacity;

    while (remainingCapacity >= cargo.weight) {
        totalCargoWeight += cargo.weight;
        totalRevenue += cargo.revenue;
        remainingCapacity -= cargo.weight;
    }

    if (remainingCapacity > 0) {
        double partialWeight = remainingCapacity;
        double partialRevenue = (partialWeight / cargo.weight) * cargo.revenue;
        totalCargoWeight += partialWeight;
        totalRevenue += partialRevenue;
    }

    double totalCost = totalCargoWeight * ship.cost;
    double profit = totalRevenue - totalCost;

    return profit;
}

//��2����ʾ���� 
void choice2(void){
	
}

//��3����ʾ���� 
void choice3(void){	

}

void pause(void){
	printf("\n\n");
	printf("��enter����\n");
	while(1){
		if(kbhit()){
			char ch=getch();
			if(ch==13){
				return;
			}
		}
	}	
}

void exit_system(void){
	system("cls");
	printf("\n\n\n\n");
	printf("final\n");
	pause();
	system("cls");
	printf("\n\n\n\n");
	printf("ffffinal");
	exit(0);
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

int main(){
	system("color F0");
	system("cls");
	int choice;
	Cargo cargo;
    Ship ship;
    bool running = true;
    
    while (running) {
    	 counter();
    	 scanf("%d",choice);
         clearInputBuffer();
	     switch(choice){
		        case 1:
		           inputParameters(&cargo, &ship);
		           system("cls");
                   printf("\t\t�ٶ������ϵ���ɱ�=(e�������η�/10)*�ٶȵ�ƽ��\n");
	               printf("\t\t                     |                        \n");
	               printf("\t\t                  �� | ��                      \n");
	               printf("\t\t                     |                        \n");
	               printf("\t\t                    \\|/                       \n");
	               printf("\t\t                                              \n");
	               printf("\t\t                   ����                       \n");
	               printf("\t\t                  e               2           \n");
	               printf("\t\t       �ɱ�  =  -----   *    �ٶ�             \n");
	               printf("\t\t                 10                           \n");
				   break;
	  	        case 2:{
			       double maxProfit = calculateMaxProfit(cargo, ship);
		           system("cls");
		           printf("�������Ϊ��$%.2lf\n", maxProfit);
			       break;
		          }
		        case 3: 
		           choice3();
				   break;
		        case 0:
		           exit_system();
				 break;
	     }
    }
    return 0;
}
