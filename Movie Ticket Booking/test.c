#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct moviedetails{
	char name[25];
	char phone[15];
	int seat;
	int id;
};
struct moviedetails person[300];
int count=0;
int m[]={10000,20000,30000};

//Function Declarations
int changeprize(int);
void reservation(int *,int,int );
int choice1();
void cancel(int *);        
void ticket1(int choice,char name[20],int id,int price);
void ticket2(int choice,char name[20],int id,int price);
void ticket3(int choice,char name[20],int id,int price);
int Moviedetails();
int movie();
void details();

int main()
{
	int **seat,choice,price=500,selection,i;
	seat=(int **)calloc(101,sizeof(int *));
	for (i=0;i<3;i++)
		*(seat+i)=(int *)calloc(101,sizeof(int ));
	
	while(1)
	{
		choice=choice1();
		switch(choice)
		{
			case 1:
				price=changeprize(price);
				break;
			case 2:
				details();
				break;	
			case 3:	
				selection=movie();
				reservation(seat[selection-1],price,selection);	
				count++;
				break;
			case 4:	
				cancel(seat);	
				break;
			case 5:
				exit(0);
				break;
			default: 
				printf("Option not available\n");
                getchar();
		        printf("\n\nPress Enter to Continue...");
		        getchar();
				break;	
		}
	}
}
int changeprize(int price)
{
	char pass[10];
	printf("Enter the password to change price of ticket: ");
	scanf("%s",pass);
	if (strcmp(pass,"pass")==0)
	{
		printf("Please enter new price: ");
		scanf("%d",&price);
		getchar();
		printf("\n\nPress Enter to Continue...");
		getchar();
	}
	else 
	{
		printf("The entered password is wrong! ");
		getchar();
		printf("\n\nPress Enter to Continue...");
		getchar();
	}
	system("clear");
	return price;
}
void reservation(int *array,int price,int selection)
{          
        system("clear");
		int i,j;
		printf("\n                                SCREEN\n\n\n");
		for (i=1;i<=100;i++)
		{
			if (array[i]==0)
				printf("%d\t",i);
			else 
				printf("*\t");	
			if(i%10==0)
				printf("\n\n");
		}
		printf("Please enter your name: ");
		getchar();
		gets(person[count].name);
		printf("Please enter your phone number: ");
		scanf("%u",&person[count].phone);
		printf("Which seat number you want? ");
		re_enter:
		scanf("%d",&j);
		if (j>100||j<1)
			{
				
				printf("seat number is unavailable in this theater\n");
				printf("Please re-enter seat number: ");
				goto re_enter;
				
			}
		if (array[j]==1)
			{
				printf("Sorry, this ticket is already booked! Please choose another seat.\n");
				goto re_enter;
			}
		else{	
			array[j]=1;
		}
		person[count].seat=j;
		if (selection==1){
			m[0]++;
			ticket1(j,person[count].name,m[0],price);
            
		}
		else if (selection==2){
			m[1]++;
			ticket2(j,person[count].name,m[1],price);
            
		}
		else if(selection==3){
			m[2]++;
			ticket3(j,person[count].name,m[2],price);
           
		}		
}
int choice1(void)
{
	system("clear");
	int choice;
    printf("||================================================================||\n");
	printf("||--------------------|    BookYourShow    |----------------------||\n");
	printf("||================================================================||\n");
	printf("||             1- To edit price of ticket (only admin):           ||\n");
	printf("||             2- To view reserved tickets (only admin):          ||\n");
	printf("||             3- To puchase ticket:                              ||\n");
	printf("||             4- To cancel the seat:                             ||\n");
	printf("||             5- Exit system:                                    ||\n");
	printf("||================================================================||\n");
	printf("\n             Enter your choice: ");
	scanf("%d",&choice);
	return choice;
}
void cancel(int *array)
{
	  system("clear");
      int Cseat,i,stop,flag=0;
	  printf("Please enter ID number of ticket: ");
	  scanf("%d",&Cseat);
	  for (i=0;i<100;i++)
	  	{
			if(Cseat==person[i].id)
			{
				flag=1;
				break;
			}
		}
	  		if(flag==1)
	  		{
					 system("clear");
					 printf("%s your seat No %d is cancelled!!!\n\n",person[i].name,person[i].seat);
					 array[person[i].seat]=0;
					 for(int k=i;k<count;k++)//For Deleting the details of Canceld Tickets
					 {
						person[k]=person[k+1];
					 }
					 count--;
	  		}
			else{
				printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
			}
		
	//   if (stop!=5)	
	//   		printf("Ticket ID number is incorrect please enter right one to cancel ticket: \n");
		getchar();
		printf("\n\nPress Enter to Continue...");
		getchar();
}

void details(void)
{
	int i,bookings=0;
	char pass[10];
    system("clear");
	printf("Enter the password to see details: ");
	scanf("%s",pass);
    
	if (strcmp(pass,"pass")==0)
	{
		int selection=Moviedetails();
            switch(selection)
            {
                case 1:
                    printf("\t-----------------THEATER BOOKING DETAILS----------------\n");
                    printf("\t-----------------|   Avengers Endgame  |----------------\n");
                    printf("\t============================================================\n");
                    //If no seats are Booked
                    for (i=0;i<count;i++)
                    {
                        if(person[i].id>10000&&person[i].id<20000){
                        	printf("\tseat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
							bookings++;
						}
                    }
					if(bookings==0)
					{
						printf("\n\t\t\t!!!!!!! NO BOOKINGS !!!!!!! \n\n");
					}
                    printf("\t============================================================\n");
                    break;
                case 2:
                    printf("\t-----------------THEATER BOOKING DETAILS----------------\n");
                    printf("\t------------------|   Captain marvel  |-----------------\n");
                    printf("\t============================================================\n");
                    for (i=0;i<count;i++)
                    {
                        if(person[i].id>20000&&person[i].id<30000){
                        	printf("\tseat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
							bookings++;
						}
                    }
					if(bookings==0)
					{
						printf("\n\t\t\t!!!!!!! NO BOOKINGS !!!!!!! \n\n");
					}
                    printf("\t============================================================\n");
                    break;
                case 3:
                    printf("\t-----------------THEATER BOOKING DETAILS----------------\n");
                    printf("\t----------------| Spiderman No way Home |---------------\n");
                    printf("\t============================================================\n");
                    for (i=0;i<count;i++)
                    {
                        if(person[i].id>30000&&person[i].id<40000){
							printf("\tseat no: %d is booked by %s booking id is %d\n",person[i].seat,person[i].name,person[i].id);
							bookings++;
						}
                    }
					if(bookings==0)
					{
						printf("\n\t\t\t!!!!!!! NO BOOKINGS !!!!!!! \n\n");
					}
                    printf("\t============================================================\n");
                    break;
                default:printf("Movie Not Available\n");
            }
            
	}
	else      
	{                                          
		printf("Entered password is wrong \n");
	}
		getchar();
		printf("\n\nPress Enter to Continue...");
		getchar();
	
}             
int movie()
{
	int i;
	system("clear");
	printf("\t\t\twhich movie you want to see?\n");
	printf("\t\t\t----------------------------\n\n");
	printf("\t\t\tpress 1 for Avengers: EndGame\n\n");
	printf("\t\t\tpress 2 for Captain Marvel\n\n");
	printf("\t\t\tpress 3 for Spider-Man: Far From Home\n");
	scanf("%d",&i);
	return i;
}
int Moviedetails()
{
	system("clear");
	int i;
	printf("\t\t\twhich movie Booking Details you want see \n");
	printf("\t\t\t-------------------------------------\n");
	printf("\t\t\tpress 1 for Avengers: EndGame\n\n");
	printf("\t\t\tpress 2 for Captain Marvel\n\n");
	printf("\t\t\tpress 3 for Spider-Man: Far From Home\n");
	scanf("%d",&i);
	system("clear");
	return i;	

}
void ticket1(int choice,char name[20],int id,int price)
{
		system("clear");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Avengers: EndGame\n",id);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 29-04-2019\n");
        printf("\t                                              Time      : 08:00pm\n");
        printf("\t                                              Hall      : 02\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
		person[count].id=id;
        printf("\t============================================================\n");
		getchar();
		printf("\n\nPress Enter to Continue...");
		getchar();
        return;
}
void ticket2(int choice,char name[20],int id,int price)
{
		system("clear");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Captain Marvel\n",id);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 15-04-2019\n");
        printf("\t                                              Time      : 09:00pm\n");
        printf("\t                                              Hall      : 03\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id;
        printf("\t============================================================\n");
		getchar();
		printf("\n\nPress Enter to Continue...");
		getchar();
        return;
}

void ticket3(int choice,char name[20],int id,int price)
{
		system("clear");
		printf("\n\n");
        printf("\t-----------------THEATER BOOKING TICKET----------------\n");
        printf("\t============================================================\n");
        printf("\t Booking ID : %d \t\t\tShow Name : Spider-Man: Far From Home \n",id);
        printf("\t Customer  : %s\n",name);
        printf("\t\t\t                              Date      : 5-07-2019\n");
        printf("\t                                              Time      : 10:00pm\n");
        printf("\t                                              Hall      : 04\n");
        printf("\t                                              seats No. : %d  \n",choice);
        printf("\t                                              price . : %d  \n\n",price);
        person[count].id=id;
        printf("\t============================================================\n");
		getchar();
		printf("\n\nPress Enter to Continue...");
		getchar();
        return;
}
