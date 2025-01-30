#include<iostream>
#include<string.h>
#include<stdio.h>
#include<conio.h>

using namespace std;
struct teacher
{
	char name[100];
	char surname[100];
	char department[100];
	char phn[100];
	char email[100];
};
int main()
{
	//cout<<"	";
	FILE *f,*fi;
	struct teacher e;
	f =fopen("text.txt","r++");
	if (f==NULL)
	{
		f= fopen("text.txt","w++");
		if (f==NULL)
		{
			return 0;
		}

	}
	int size=sizeof(e);
	while(1) {
	    cout << "\n\t\t\t\t\t\t====== BSMRSTU TEACHER RECORD DATABASE ======";
        cout << "\n\n";
        cout << "\n \t\t\t\t\t\t 1. Join New teacher";
        cout << "\n \t\t\t\t\t\t 2. Search Teacher";
        cout << "\n \t\t\t\t\t\t 3. All Teacher of BSMRSTU (View  List Records)";
        cout << "\n \t\t\t\t\t\t 4. Change Records Or Promotion (Data Update)";
        cout << "\n \t\t\t\t\t\t 5. Transfar Teacher/ Retiring Teacher (Delete Data)";

        cout << "\n \t\t\t\t\t\t 6. Teacherlist in Department ";
        cout << "\n \t\t\t\t\t\t 7. Exit   Program";
        cout << "\n\n";
        cout << "\t\t\t\t\t\t Select Your Choice :=> ";
        fflush(stdin);

		int chose;
		cin>>chose;
		switch(chose)
		{

			case 1:
			{
				fseek(f,0,SEEK_END);
				system("cls");
				fflush(stdin);
				cout<<"New Teachar name : ";
				gets(e.name);
				cout<<"Designation : ";
				gets(e.surname);
				fflush(stdin);
				cout<<"Department : ";
				gets(e.department);
				cout<<"Phone Noumber(without +88) : ";
				gets(e.phn);
				cout<<"Email : ";
				gets(e.email);
				//fprintf(f, "%s %s %s %s %s", e.name, e.roll, e.couseName ,e.section);
				fwrite(&e,size,1,f);
				cout<<"\nRecord succesfully\n";
                system("pause");
                system("cls");
                break;
            }
            case 2:
            {
            	system("cls");
            	fflush(stdin);
            	cout<<"Enter Teachar Name => ";
            	char Name[100];
            	gets(Name);
            	rewind(f);
            	cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            	cout<<"_________________________________________________________________________________________________________________________________\n\n";

            	while(fread(&e,size,1,f) == 1){
            	    if ((strcmp(e.name,Name)==0))
            	    {
            			printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
            		}
            	}
            	system("pause");
                system("cls");
            	break;
            }
            case 3:
            {
            	system("cls");
            	rewind(f);
            	cout << "\t\t\t\t\t\t=== View the Records in the Database ===";
            	cout << "\n\n\n";
            	cout<<"\t\t\t\t\t\tVice Chancellor = A. Q. M. Mahbub\n"<<endl;
            	cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            	cout<<"_________________________________________________________________________________________________________________________________\n\n";

            	while (fread(&e,size,1,f) == 1)
            	{
                	cout << "\n";
                	//cout <<"\n" << e.name <<"\t\t"<< e.surname<<"\t\t" <<e.department<<"\t\t"<<e.phn;
                	printf("%-30s%-35s%-31s%-22s%-23s\n", e.name,e.surname,e.department,e.phn,e.email);

            	}
            	cout << "\n\n";
            	system("pause");
            	system("cls");
            	break;
            }
            case 4:
            {
            	system("cls");

            	cout<<"Enter Phone number(without +88) or Email:";
            	char R[100];
            	int zz=0;
            	cin>>R;
            	rewind(f);
            	while(fread(&e,size,1,f) == 1){
            	    if ((strcmp(e.phn,R)==0) || (strcmp(e.email,R)==0))
            	    {
            	    	cout<<"Data founded"<<endl;
            	    	fflush(stdin);
						cout<<"Correct name : ";
						gets(e.name);
						fflush(stdin);
						cout<<"Designation : ";
						gets(e.surname);
						fflush(stdin);
						cout<<"Department Name : ";
						gets(e.department);
						cout<<"Phone Number : ";
						gets(e.phn);
						fflush(stdin);
						cout<<"Email : ";
						gets(e.email);
						fseek(f, - size, SEEK_CUR);
                    	fwrite(&e,size,1,f);
                    	zz++;
                    	break;
            	    }
            	}
            	if (zz==0)
            	{
            		cout<<"\nData Not founded."<<"\n\n"<<"Please!, Try again and Write a Correct Data.\n"<<endl;
            		zz=0;
            	}
            	system("pause");
            	system("cls");
            	break;
            }
            case 5:
            {
            	system("cls");
            	int out=0;
            	fflush(stdin);
            	cout<<"Teachers Email : ";
            	char k[100];
            	gets(k);
            	fi=fopen("text2.dat","wb");
            	rewind(f);
            	while(fread(&e,size,1,f)==1)
            	   if ((strcmp(e.email,k)!=0))
            	   {
            	   		fwrite(&e,size,1,fi);
            	   }
            	   else
            	   	out++;

            	fclose(f);
            	fclose(fi);
            	remove("text.txt");
            	rename("text2.dat","text.txt");
            	f=fopen("text.txt","rb+");
            	if(out>0)
            		cout<<"Delete succesfully"<<endl;
            	else
            		cout<<"\nEmail not found, Pleaase!, Try again and write Correct Email.\n"<<endl;
            	system("pause");
                system("cls");
            	break;
            }
            case 7:
            {
            	system("cls");
            	cout<<" Exit program"<<endl;
            	return 0;
            }
           	case 6:
            {
            	system("cls");
            	cout << "\n \t\t\t 1. Engineering Faculty";
            	cout << "\n \t\t\t 2. Science Faculty";
            	cout << "\n \t\t\t 3. Life Science Faculty";
            	cout << "\n \t\t\t 4. Business Studies Faculty";
            	cout << "\n \t\t\t 5. Social Science Faculty";
            	cout << "\n \t\t\t 6. Humanities Faculty";
            	cout << "\n \t\t\t 7. Law Faculty";
            	cout << "\n \t\t\t 8. Agriculture Faculty\n\n";
            	int fa;
            	cout<<"Select Faculty => ";
            	cin>>fa;
            	switch(fa)
            	{
            		case 1:
            		{
            			system("cls");
            			cout << "\n \t\t\t\t 1. Computer Science And Engineering Department";
	            		cout << "\n \t\t\t\t 2. Electrical and Electronic Engineering Department";
	            		cout << "\n \t\t\t\t 3. Aplied Chemistry And Chemical Engineering Department";
	            		cout << "\n \t\t\t\t 4. Civil Engineering Department";
	            		cout << "\n \t\t\t\t 5. Architrihure Department";
	            		cout << "\n \t\t\t\t 6. Food And Agro process Engineering Department\n\n";
	            		int en;
	            		cout<<"Select Department => ";
	            		cin>>en;
	            		switch(en)
	            		{
	            			case 1:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Computer Science And Engineering Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"CSE")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 2:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\t Teacher list at Electrical and Electronic Engineering Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"EEE")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 3:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher list at Aplied Chemistry And Chemical Engineering Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"ACCE")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 4:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\t Teacher list at Civil Engineering Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"CE")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 5:
	            			{
	            				system("cls");

	            				cout << "\n \t\t\t\tTeacher list at Architrihure Department\n\n";
	            				// cout<<"N/A"<<endl;;
	            				// cout<<"Have a No teacher";
	            				// break;
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"ARC")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 6:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher list at Food And Agro process Engineering Department\n\n";
	            				// cout<<"N/A"<<endl;;
	            				// cout<<"Have a No teacher";
	            				// break;
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"FAE")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            		}

	            		break;
            		}
            		case 2:
            		{
            			system("cls");
            			cout << "\n \t\t\t\t 1. Mathematics Department";
		            	cout << "\n \t\t\t\t 2. Statistics Department";
		            	cout << "\n \t\t\t\t 3. Chemistry Department";
		            	cout << "\n \t\t\t\t 4. Physics Department";
		            	cout << "\n \t\t\t\t 5. Enviromental Science And Diasester Management Department\n\n";
		            	int sc;
		            	cout<<"Select Department => ";
		            	cin>>sc;
		            	switch(sc)
	            		{
	            			case 1:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Mathematics Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"MAT")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 2:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Statistics Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"STA")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 3:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Chemistry Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"CHE")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 4:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Physics Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"PHY")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 5:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Enviromental Science and And Diasester Management Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"ESD")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            		}

		            	break;
            		}
            		case 3:
            		{
            			system("cls");
            			cout << "\n \t\t\t\t 1. Pharmacy Department";
	            		cout << "\n \t\t\t\t 2. Bio-Chemistry And Molicular Biology Department";
	            		cout << "\n \t\t\t\t 3. Bio-Tecnology And Genetic Engineering Department";
	            		cout << "\n \t\t\t\t 4. Psychics Department";
	            		cout << "\n \t\t\t\t 5. Botany Department";
	            		int bio;
		            	cout<<"\n\nSelect Department => ";
		            	cin>>bio;
		            	switch(bio)
	            		{
	            			case 1:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Pharmacy Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"PHR")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 2:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Bio-Chemistry And Molicular Biology Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"BMB")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 3:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Bio-Tecnology And Genetic Engineering Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"BGE")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 4:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Psychics Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"PSY")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 5:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Botany Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"BOT")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            		}
	            		break;
            		}
            		case 4:
            		{
            			system("cls");
            			cout << "\n \t\t\t\t 1. Management Studies Department";
		            	cout << "\n \t\t\t\t 2. Marketing Department";
		            	cout << "\n \t\t\t\t 3. Finance and Banking Department";
		            	cout << "\n \t\t\t\t 4. Accounting And information System Department";
		            	cout << "\n \t\t\t\t 5. Tourism and Hospitality Management Department";
		            	int bsf;
		            	cout<<"\n\nSelect Department => ";
		            	cin>>bsf;
		            	switch(bsf)
	            		{
	            			case 1:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Management Studies Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"MAG")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 2:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Marketing Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"MKT")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 3:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Finance and Banking Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"FAB")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 4:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Accounting And information System Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"AIS")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 5:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Tourism and Hospitality Management Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"THM")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            		}
		            	break;

            		}
            		case 5:
            		{
            			system("cls");
            			cout << "\n \t\t\t\t 1. Economics Department";
		            	cout << "\n \t\t\t\t 2. Sociology Department";
		            	cout << "\n \t\t\t\t 3. Public Administation Department";
		            	cout << "\n \t\t\t\t 4. Political science Department";
		            	cout << "\n \t\t\t\t 5. International Relation Department";
		            	int ssf;
		            	cout<<"\n\nSelect Department => ";
		            	cin>>ssf;
		            	switch(ssf)
	            		{
	            			case 1:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Economics Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"ECO")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 2:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at  Sociology Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"SOC")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 3:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Public Administation Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"PAD")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 4:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Political science Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"PSC")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 5:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at International Relation Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"IR")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            		}

		            	break;

            		}
            		case 6:
            		{
            			system("cls");
            			cout << "\n \t\t\t\t 1. English Department";
            			cout << "\n \t\t\t\t 2. Bangla Department";
            			cout << "\n \t\t\t\t 3. History Department";
            			int arc;
		            	cout<<"\n\nSelect Department => ";
		            	cin>>arc;
		            	switch(arc)
	            		{
	            			case 1:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at English Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"ENG")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 2:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Bangla Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"BAN")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 3:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Hstory Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"HIS")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            		}
            			break;
            		}
            		case 7:
            		{
            			system("cls");
            			cout << "\n \t\t\t\t 1. Law Department";
            			int la;
		            	cout<<"\n\nSelect Department => ";
		            	cin>>la;
		            	switch(la)
	            		{
	            			case 1:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Law Department";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"LAW")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            		}
            			break;
            		}
            		case 8:
            		{
            			system("cls");
            			cout << "\n \t\t\t\t 1. Agriculture Departmant";
            			cout << "\n \t\t\t\t 2. Fisheries And Marine Bioscience Departmant";
            			cout << "\n \t\t\t\t 3. Animals Science And Veterinary Medicince Departmant";
            			int ssf;
		            	cout<<"\n\nSelect Department => ";
		            	cin>>ssf;
		            	switch(ssf)
	            		{
	            			case 1:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Agriculture Departmant";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"AGR")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 2:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Fisheries And Marine Bioscience Departmant";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"FMB")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            			case 3:
	            			{
	            				system("cls");
	            				cout << "\n \t\t\t\tTeacher List at Animals Science And Veterinary Medicince Departmant";
	            				rewind(f);
	            				cout<<"\n\nName\t\t\t\tDesignation\t\t\tDepartmant\t\t\tPhone number\t\tEmail\n";
            					cout<<"_________________________________________________________________________________________________________________________________\n\n";
            					while(fread(&e,size,1,f) == 1){
				            	    if (strcmp(e.department,"ASVM")==0)
				            	    {
				            	    	printf("%-30s%-35s%-31s%-22s%-23s\n\n", e.name,e.surname,e.department,e.phn,e.email);
				            	    }
				            	}
				            	system("pause");
            					system("cls");
			            	    break;
	            			}
	            		}
            			break;
            		}
            	}

            	break;
            }


        }
	}
}
