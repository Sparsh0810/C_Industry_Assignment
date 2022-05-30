/*!including input output stdio & stdlib header file*/
 #include<stdio.h>
 #include<stdlib.h>
 
void addemployee();                     //!< declaration of addemployee function
void employeerecord();                  //!< declaration of employeerecord function
void searchemployee();                  //!< declaration of asearchemployee function
void delete();                          //!< declaration of delete function
 
  struct employee {                             //!< Structure of all the Employee details 
    char first_name[20];
    char last_name[20];
    int global_id;
    char Course[20];
     char Address[20];
    float Salary;
};
 
void main()
{
    
    int choice=0;
    while(choice!=5){               //this loop will continue until user enter 5 as choice
        
    printf("=====EMPLOYEES DATABASE MANAGEMENT SYSTEM=====\n");
    printf("1. Add employee\n");
    printf("2. Employees Records\n");
    printf("3. Search Employee\n");
    printf("4. Delete Employee\n");
    printf("5. Exit\n");
    printf("\n");
    scanf("%d",&choice);

   switch(choice){
       case 1:                                                      //Case is picked when expression gives 1
          addemployee();
         break;
     case 2:                                                        //Case is picked when expression gives 2
          employeerecord();
          printf("press any key to exit..... \n");
         break;
        
     case 3:                                                        //Case is picked when expression gives 3
         searchemployee();
         printf("Press any key to exit.......\n");
         break;
  
     case 4:                                                        //Case is picked when expression gives 4
        delete();
        printf("Press any key to exit.......\n");
        break;
     case 5:                                                       //Case is picked when expression gives 5
          printf("Thank you, for used this software.\n\n");
          exit(0);
        break;
        
     default :                                                           // When value of expression didn't match with any case
         printf("Enter a valid number\n\n");
         printf("Press any key to continue.......");
	
         break;
        }
  
        }

     }
    
 void addemployee(){                                        // definition of addemployee function which take no parameter to add employee information of all user
   
     char another;
     FILE *fp;
     int n,i;
     struct employee info;
   do{
       printf("=======Add employees Info=======\n\n\n"); 
fp=fopen("information.txt","a");      		              //use can give any file name. Give the name with extention or without extention.
         
        printf("Enter First Name     : ");
          scanf("%s",info.first_name);                                  /*!storing first name in Structure data member first_name using info varible */
          printf("Enter Last Name     : ");
          scanf("%s",info.last_name);                                   /*!storing last name in Structure data member last_name using info varible */
          printf("Enter Global-ID      : ");
          scanf("%d",&info.global_id);                                  /*!storing global id in Structure data member global_id using info varible */
          printf("Enter Class(course) : ");
          scanf("%s",info.Course);                                      /*!storing Course  in Structure data member Course using info varible */
          printf("Enter Address       : ");
          scanf("%s",info.Address);                                     /*!storing Address  in Structure data member Address using info varible */
          printf("Enter Salary    : ");
          scanf("%f",&info.Salary);                                     /*!storing Salary  in Structure data member Salary using info varible */
       
      if(fp==NULL){
        fprintf(stderr,"can't open file");
    }else{
        printf("\t\t\tRecord stored successfuly\n");
    }
    
    fwrite(&info, sizeof(struct employee), 1, fp); 
    fclose(fp);
    
    printf("\t\t\tYou want to add another record?(y/n) : ");
    
    
    scanf("%s",&another);
    
    
   }while(another=='y'||another=='Y');
}
 
 void employeerecord(){                                 // definition of employee record function which take no parameter to find record employee information of all user
   
     FILE *fp;
 
    struct employee info;
    fp=fopen("information.txt","r");                    //it open file information.txt in read mode
    
     printf("=======EMPLOYEES RECORD=======\n\n\n");
      
    if(fp==NULL){
        
        fprintf(stderr,"can't open file\n");
        exit(0);
    }else{
        printf("RECORDS :\n");
    }
        
        while(fread(&info,sizeof(struct employee),1,fp)){
        printf("\nemployee Name  \n: %s %s",info.first_name,info.last_name);                /*!displaying First name & Last name of user*/
        printf("\nGlobal ID       \n: %d",info.global_id);                                  /*!displaying global id of user*/
        printf("\nClass         \n: %s",info.Course);                                       /*!displaying course of user*/
        printf("\nAddress       \n: %s",info.Address);                                      /*!displaying address of user*/
        printf("\nSalary        \n: %f",info.Salary);                                       /*!displaying Salary of user*/
      
         }
        fclose(fp);
      
  }
 
void searchemployee(){                                      // definition of searchemployee function which take no parameter to search employee information of all user
       struct employee info;
      FILE *fp;
      int global_id,found=0;
     
    fp=fopen("information.txt","r");                        //it open file information.txt in read mode
    printf("=======SEARCH EMPLOYEES RECORD=======\n\n\n");
    printf("Enter the global id : ");
   
    scanf("%d",&global_id);
     
    
    
    while(fread(&info,sizeof(struct employee),1,fp)>0){
         
        if(info.global_id==global_id){                                  /*!condition to check user global_id match to global_id or not if it match record info will be shown*/
           
        found=1;
        printf("\nEmployee Name \n: %s %s",info.first_name,info.last_name);    /*!displaying First name & Last name of user*/
        printf("\nGlobal ID       \n : %d",info.global_id);                     /*!displaying global id of user*/
        printf("\nClass          \n: %s",info.Course);                         /*!displaying course of user*/
        printf("\nAddress        \n: %s",info.Address);                        /*!displaying Address of user*/
        printf("\nSalary        \n : %f",info.Salary);                         /*!displaying Salary of user*/ 
  
         }
       
    }
     
    if(!found){
       printf("\n\t\t\tRecord not found\n");
    }
  
    fclose(fp);

}
 
 
 void delete(){                                     // definition of delete function which take no parameter to delete employee information of all user
      struct employee info;
      FILE *fp, *fp1;
     
       
    int global_id,found=0;
    
    printf("=======DELETE EMPLOYEES RECORD=======\n\n\n");
    fp=fopen("information.txt","r");
    fp1=fopen("temp.txt","w");                              //it open file temp.txt in write mode
    printf("Enter the global id : ");
    scanf("%d",&global_id);
    if(fp==NULL){
         fprintf(stderr,"can't open file\n");
         exit(0);
      }
    
    while(fread(&info,sizeof(struct employee),1,fp)){
        if(info.global_id == global_id){              /*!condition to check user global_id match to global_id or not if it match record info will be shown*/
          
            found=1;
        
        }else{
           fwrite(&info,sizeof(struct employee),1,fp1);
        }
  
    }
     fclose(fp);
     fclose(fp1);
 
    if(!found){
          printf("Record not found\n");
        }
      if(found){ 
    remove("information.txt");
        rename("temp.txt","information.txt");
        
        printf("Record deleted succesfully\n");
        }
 
  }
