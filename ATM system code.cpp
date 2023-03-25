#include <iostream>
#include <cstring>
#include <limits>
using namespace std;
void menu() {//This function only used to be called to show the menu to the user.
	cout << "1----Create new account" << endl;
	cout << "2----Deposit" << endl;
	cout << "3----transfer to another account" << endl;
	cout << "4----withdrawal" << endl;
	cout << "5----exit" << endl;
}
class ATM {
	char Account_name[100];
	char Card_number[11];
	int same_integer;
	int similar;
	double Amount;//account money balance
public:
	void Print_acc_data() {//shows data
		cout << "name: " << Account_name << endl;
		cout << "card number: ";
		for (int k = 0; k < 10; k++) {
			cout <<  Card_number[k];
		}
		cout << endl;
		cout << "amount: " << Amount<<endl;
	}
	void create_new_acc(ATM users[],int index) {
	bool valid = false;
	while(!valid){
		cout << "please enter the account name: ";
		cin.ignore();
		enter_accname_again:
		cin.getline(Account_name, 100);
		if(cin.fail()){
			valid = false;
			cout << endl << "name can't be longer than 100 characters" << endl;
			cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            char x='1';
            cin>>x;
            	} // end fail check

		else valid = true;

	}

if(strlen(Account_name)==0){//check if input name is null
        cout<<"account name is null which is invalid!"<<endl;
         cout<<"please enter the account name: ";
goto enter_accname_again;
}



		for(int i=0;i<strlen(Account_name);i++){//check if input is anything except character and spaces
                if((int(Account_name[i])>=65&&int(Account_name[i])<=90)||((int(Account_name[i])>=97)&&(int(Account_name[i])<=122))||int(Account_name[i])==32){}
                else{
                    cout<<"please enter english letters only!"<<endl;
                    cout<<"please press enter to continue!"<<endl;
                    cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    cout<<"please enter the account name: ";
                    goto enter_accname_again;
                }
		}

		bool allspace;
for(int i=0;i<strlen(Account_name);i++){//check if name is all spaces
    if(int(Account_name[i])==32)
    {
        allspace=true;
    }
    else{
        allspace=false;
        break;
    }
}
if(allspace){
    cout<<"Account name can't be only spaces!"<<endl;
    cout<<"please enter the account name: ";
        goto enter_accname_again;
}
		create_card_number:


		valid=false;
		while(!valid){
		cout<< "Please enter the account number(10 numbers): ";
		cin.getline(Card_number, 11, '\n');
		for(int i=0; Card_number[i]; i++){
            if(int(Card_number[i])>=48 && int(Card_number[i])<=57)
                    valid=true;
                else{
                        cout<<"enter only numbers "<<endl;
                        cout<<"Please enter the account number(10 numbers): ";
                        cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
                    goto create_card_number;
                }
                if(valid){

   if(strlen(Card_number)<10){
    cout<<"Account number can't be shorter than 10!"<<endl;
    goto create_card_number;
}
bool equal;
if(index==0)
    goto skip;
for(int k=0;k<index;k++){
    for(int j=0;j<10;j++){
        if(int(users[k].Card_number[j])==int(Card_number[j])){
            equal=true;
        }
        else{
            equal=false;
            goto end1stloop;
        }

    }end1stloop:
    if(equal){
            cout<<"number is already taken by another user!"<<endl;
        goto endloop;
    }
}
endloop:
if(equal==true){
    goto create_card_number;
}
skip:
		if(cin.fail()){
			valid = false;
			cout << endl << "Number can't be longer than 10 numbers!" << endl;
			cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            goto create_card_number;
            	} // end fail check

		else valid = true;
		}


	}}

		similar=0;
			for (int i = 0; i < 9; i++){//to reject the case of entering a card number all of the same integer
                if(Card_number[i]==Card_number[i+1])
                    similar++;
			else break;
			}
			if(similar==9)
            {
              cout<<"Invalid card number..a card number can't be all of the same integer,please enter a valid one: ";
                goto create_card_number;
            }
		Amount = 0;
		Print_acc_data();
	}
	void Deposit(double Deposit_amount) {
		Amount += (Deposit_amount + (Deposit_amount * 0.01));
		Print_acc_data();
	}
	void Withdrawal(double Withdrawn_amount) {
		Amount -= (Withdrawn_amount + (Withdrawn_amount * 0.03));
		Print_acc_data();
	}
	void Transfer(double value,ATM &sender,ATM &receiver) {
	 receiver.Amount+=(value-(value*0.015));//reciever
	 sender.Amount-=(value+(value*0.015));//sender
	 cout<<"sending account:"<<endl;
	 sender.Print_acc_data();
	 cout<<"receiving account:"<<endl;
     receiver.Print_acc_data();


	}

	bool search_accounts(char account_num[]){//case of rejection of entering a card number that is already taken
    same_integer=0;
    for (int i=0; i<10; i++)
       {
        if(account_num[i]!=Card_number[i])

                 return false;
               else  same_integer++;
       }
       if(same_integer==10)
                return true;

	}
bool check_withdrawn_money(double Withdrawn_amount){
if(1.03*Withdrawn_amount>Amount){//to check if the money the user wants to withdraw +3% of it is less than the total amount in the account or not
    cout<<"invalid...the maximum amount that can be withdrawn is: "<<Amount*1.03<<endl;
return true;
}
    return false;
}
bool check_transfer_money(double transfer_amount,ATM &sender,ATM &receiver){
if(1.015*transfer_amount>sender.Amount){//to check if the money the user wants to transfer+1.5% of it is less than the total amount of his account
    cout<<"invalid...the maximum amount that can be transfered is: "<< sender.Amount*1.015<<endl;
    return true;}
return false;
}
};
int main()
{
	int i = 0;
	int operation;
	ATM atm_users[100];
	int k,m;
	bool j;
    int user_index;
    int sender_index;
    int reciever_index;
	do {
		menu();
		repeat_operation:
		bool valid =false;
		while(!valid){
        cout << "Please enter the number of operation: " ;
		cin >> operation;
		cout<<'\b';
		if((!cin)||(cin.peek()!='\n')){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"Wrong input...please enter the integer from 1 to 5 corresponding to the process you want"<<endl;
            goto repeat_operation;
		}
		else valid = true;
	}
if(operation == 1||operation==2||operation==3||operation==4||operation==5){
		if (operation == 5)
			break;
			if (operation == 1 && i < 100)
			{

				atm_users[i].create_new_acc(atm_users,i);
                i++;
                if (i == 100)
                cout << "That was the last account that could be added!" << endl;
			}
			if (operation == 1 && i == 100) {
				cout << "Maximum number of accounts reached!" << endl;
			}

        if (operation == 2) {char account_number[11];
				double Deposit_amount;
				cout << "Please enter the account number(10 numbers): ";
				cin.ignore();
				ree:
				cin.getline(account_number, 11, '\n');
				if(i==0){
                        cout<<"No accounts created...create an account first"<<endl;
                    goto repeat_operation;
					}
if(strlen(account_number)<10){
        cout<<"complete 10 numbers!"<<endl;
    for(int i=strlen(account_number);i<=9;i++)
    {
        cin>>account_number[i];
    }
}

		if(cin.fail()){
			valid = false;
			cout << endl << "Number can't be longer than 10 numbers!" << endl;
			cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please enter the account number(10 numbers): ";
            goto ree;
            	} // end fail check

		else valid = true;


					cout<<'\b';
				here:	int k=0;
					start: while(k<i)
					{
                       j=  atm_users[k].search_accounts(account_number);
                       if(j==false){
                        k++;
                        goto start;
                       }else break;
					}
					if(j==false){
                      cout<<"invalid account number,Please enter the account number(10 numbers): ";
                      for (int m = 0;m< 10;m++)
					cin >> account_number[m];
					 goto here;
					}
					user_index=k;
					repeat_amount:
cout<<"Please enter the amount to be deposited: ";
					cin>>Deposit_amount;


					if((!cin)||(cin.peek()!='\n')||Deposit_amount<=0)//this if condition is used to check if the amount input contains anything but integers  and if it is a positive number
             {
              cout<<"INCORRECT INPUT!\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cout<<"ENTER A VALID ONE.\n";
              goto repeat_amount;
             }



					cout<<'\b';
atm_users[user_index].Deposit(Deposit_amount);
			}
			if (operation == 4) {
			cout << "Please enter the account number(10 numbers): ";
				char account_number[12];
				double Withdrawn_amount;
				cin.ignore();
				reeee:
				    cin.getline(account_number,11);
				    if(i==0){
                        cout<<"No accounts created...create an account first"<<endl;
                    goto repeat_operation;
					}
if(strlen(account_number)<10){
    for(int i=strlen(account_number);i<=9;i++)
    {
        cin>>account_number[i];
    }
}

if(cin.fail()){
			valid = false;
			cout << endl << "Number can't be longer than 10 numbers!" << endl;
			cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            cout<<"Please enter the account number(10 numbers): ";
            goto reeee;
            	}

					cout<<'\b';
					there: int k=0;
					loop:while(k<i){
					j=  atm_users[k].search_accounts(account_number);
					if(j==false){
                        k++;
                        goto loop;
                       }
                       else break;
					}
					if(j==false){
                      cout<<"invalid account number,Please enter the account number(10 numbers): ";
                      for (int m = 0;m< 10;m++)
					cin >> account_number[m];
					 goto there;
					}
					user_index=k;

					cout<<"please enter the amount to be withdrawn: ";
					repeat_withdraw_amount:
					cin>>Withdrawn_amount;

								if((!cin)||(cin.peek()!='\n')||Withdrawn_amount<=0)//this if condition is used to check if the amount input contains anything but integers  and if it is a positive number
             {
              cout<<"INCORRECT INPUT!\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cout<<"Please enter positive integers only.\n";
              goto repeat_withdraw_amount;
             }



					cout<<'\b';

					while(atm_users[user_index].check_withdrawn_money(Withdrawn_amount)){//to check if the money the user wants to withdraw +3% of it is less than the total amount in the account or not
                            cout<<"please enter the amount to be withdrawn: ";
					cin>>Withdrawn_amount;
					cout<<'\b';
					atm_users[user_index].check_withdrawn_money(Withdrawn_amount);
					}
					atm_users[user_index].Withdrawal(Withdrawn_amount);

			}
			if (operation == 3) {
			cout << "Please enter the number of the sending account(10 numbers) :";
			char account_number_sender[11];
				double transfer_amount;
			for (int m = 0; m < 10; m++)
					cin >> account_number_sender[m];
					cout<<'\b';
					if(i==0){
                        cout<<"No accounts created...create an account first"<<endl;
                    goto repeat_operation;
					}
					exist: int k=0;
					check:while(k<i){
					j=  atm_users[k].search_accounts(account_number_sender);
					if(j==false){
                        k++;
                        goto check;
                       }
                       else break;
					}
					if(j==false){
                      cout<<"invalid account number,please enter your account number(10 numbers): ";
                      for (int m = 0;m< 10;m++)
					cin >> account_number_sender[m];
					 goto exist;
					}
					sender_index=k;
            cout << "Please enter the number of the receiving account(10 numbers) :";
            char account_number_reciever[11];
            for (int m = 0; m < 10; m++)
					cin >> account_number_reciever[m];
					cout<<'\b';
						if(i==1){
                        cout<<"only 1 account is created...create another account "<<endl;
                    goto repeat_operation;
					}
						existence: k=0;
					repeat:while(k<i){
					j=  atm_users[k].search_accounts(account_number_reciever);
					if(j==false){
                        k++;
                        goto repeat;
                       }
                       else break;
					}
					if(j==false){
                      cout<<"invalid account number,please enter receiver account number(10 positive integers): ";
                      for (int m = 0;m< 10;m++)
					cin >> account_number_reciever[m];
					 goto existence;
					}
					reciever_index=k;
				repeat_transfer_amount:
            cout<<"please enter the amount to be transferred: ";
             cin>>transfer_amount;
             cout<<'\b';
   if((!cin)||(cin.peek()!='\n')||transfer_amount<=0)//this if condition is used to check if the amount input contains anything but integers  and if it is a positive number
             {
              cout<<"INCORRECT INPUT!\n";
              cin.clear();
              cin.ignore(numeric_limits<streamsize>::max(), '\n');
              cout<<"ENTER A VALID ONE.\n";
              goto repeat_transfer_amount;
             }

while(atm_users[sender_index].check_transfer_money(transfer_amount,atm_users[sender_index],atm_users[reciever_index])){

   cout<<"please enter the amount to be transferred: ";
             cin>>transfer_amount;
             cout<<'\b';
             atm_users[sender_index].check_transfer_money(transfer_amount,atm_users[sender_index],atm_users[reciever_index]);
}
atm_users[sender_index].Transfer(transfer_amount,atm_users[sender_index],atm_users[reciever_index]);
}
}
else{
    cout<<"Wrong input...please enter the integer from 1 to 5 corresponding to the process you want"<<endl;
    goto repeat_operation;
	} }while (operation != 5);
	return 0;
}
