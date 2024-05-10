#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    double weight;   // 货物重量
    double revenue;   // 货物利润
} Cargo;

// 定义船舶的结构体
typedef struct {
    double capacity;    // 船舶载重量容量
    double speed;      // 船舶运输速度
    double cost;       // 船舶运输成本
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

//运行后先清屏后显示主菜单 
void counter(void){
	system("cls");
	caidan();
}

//主菜单函数 
void caidan(void){
	system("cls");
	caidan_print();
}

//键盘输入指引 
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

//主菜单显示选项 
void caidan_print(void){
	printf("\t\t--------------------\n");
    printf("\t\t商船运输装载分析系统\n");
    printf("\t\t--------------------\n");
    printf("\t\t1. 输入参数\n");
    printf("\t\t2. 计算利润\n");
    printf("\t\t3. 退出\n");
    printf("\t\t--------------------\n");
    printf("\t\t请选择操作按（1-3）：");
}

//按1后显示界面 
void inputParameters(Cargo *cargo, Ship *ship) {
	system("cls"); 
	printf("\n\n\n\n");
    printf("\n\t请输入货物重量：");
    scanf("%lf", &cargo->weight);
    printf("\n\t请输入货物利润：");
    scanf("%lf", &cargo->revenue);
    printf("\n\t请输入船舶载重量容量：");
    scanf("%lf", &ship->capacity);
    printf("\n\t请输入船舶运输速度：");
    scanf("%lf", &ship->speed);
    printf("\n\t请输入船舶运输成本：");
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

//按2后显示界面 
void choice2(void){
	
}

//按3后显示界面 
void choice3(void){	

}

void pause(void){
	printf("\n\n");
	printf("按enter继续\n");
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
                   printf("\t\t假定满足关系：成本=(e的重量次方/10)*速度的平方\n");
	               printf("\t\t                     |                        \n");
	               printf("\t\t                  如 | 下                      \n");
	               printf("\t\t                     |                        \n");
	               printf("\t\t                    \\|/                       \n");
	               printf("\t\t                                              \n");
	               printf("\t\t                   重量                       \n");
	               printf("\t\t                  e               2           \n");
	               printf("\t\t       成本  =  -----   *    速度             \n");
	               printf("\t\t                 10                           \n");
				   break;
	  	        case 2:{
			       double maxProfit = calculateMaxProfit(cargo, ship);
		           system("cls");
		           printf("最大利润为：$%.2lf\n", maxProfit);
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
