struct user 
{ 
 char fname[30]; 
 char lname[30]; 
 char phno[15]; 
 int mem_plan,no_bk; 
 float amt; 
 char username[20];  
 char password[30]; 
 int borrowed[4]; 
 int no_borrowed; 
};
extern struct user u[3];