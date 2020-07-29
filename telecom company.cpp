#include<iostream>
#include <stdlib.h>
#include <thread>
using namespace std;
// passwords --->  Alex : 111 , Antonius : 222 , Steve : 333 , Marry : 444 , Francesca : 555 
struct Userdata
{
	string
		name = "0",
		E_mail = "0",
		telVodafone = "0",
		telOrange = "0",
		telEtisalat = "0",
		password = "0";
	float
		Orangebalance = 20,
		Vodafonebalance = 20,
		Etisalatbalance = 20,
		Orangeflex = 80,
		Vodafoneflex = 80,
		Etisalatflex = 80;
	int
		ID = 0;

}user1, user2, user3, user4, user5, temp;

char Userchoice;
string  TelNumber, userpasschek, serialNumber;
string srialnumbers[3] = { "111555" , "111000" , "111555" };
int UserID;
float balance, BalanceTransfer, flex;
bool FlexPackage = 0;

void Data();
void Saving_Data();

void card_serial_Number();
void card_charge();
void Balance_Recharge();

void Package_Type();

void Balance_Transfer_Value();

void Balance_Transfer_Vodafone_Mange();
void Balance_Transfer_Vodafone();

void Balance_Transfer_Etislate_Mange();
void Balance_Transfer_Etislate();

void Balance_Transfer_Orange_Mange();
void Balance_Transfer_Orange();

void User_Options_Choises();
void User_Options();

void Sign_In();

void Choose_Network_Option();
void Choose_Network();

void Main_Menu();
void Main_Menu_Options();

int main() {
	system("Color F0");// to make console back ground color white and text color black , can do it too from propertise 
	Data();
	Main_Menu();
	return 0;
}

void Data()
{

	user1.name = "Alex";
	user1.ID = 111;
	user1.telVodafone = "010000000010";
	user1.telEtisalat = "011000000010";
	user1.telOrange = "012000000010";
	user1.E_mail = "Alex@yahoo.com";
	user1.password = "111";

	user2.name = "Antonius";
	user2.ID = 112;
	user2.telVodafone = "010000000020";
	user2.telEtisalat = "011000000020";
	user2.E_mail = "Antonius@yahoo.com";
	user2.password = "222";

	user3.name = "Steve";
	user3.ID = 113;
	user3.telVodafone = "010000000030";
	user3.telEtisalat = "011000000030";
	user3.telOrange = "012000000040";
	user3.E_mail = "Steve@yahoo.com";
	user3.password = "333";

	user4.name = "Marry";
	user4.ID = 114;
	user4.telVodafone = "010000000040";
	user4.E_mail = "Marry@yahoo.com";
	user4.password = "444";

	user5.name = "Francesca";
	user5.ID = 115;
	user5.telVodafone = "010000000050";
	user5.telOrange = "012000000050";
	user5.E_mail = "Francesca@yahoo.com";
	user5.password = "555";

}
void Saving_Data()
{
	//This function is to save each user's data in his own data after modifying it after it was in the template
	if (TelNumber == temp.telVodafone)
	{
		temp.Vodafonebalance = balance;
		temp.Vodafoneflex = flex;
	}
	else if (TelNumber == temp.telEtisalat)
	{
		temp.Etisalatbalance = balance;
		temp.Etisalatflex = flex;
	}
	else
	{
		temp.Orangebalance = balance;
		temp.Orangeflex = flex;
	}

	switch (temp.ID)
	{
	case 111:
		user1 = temp;
		break;
	case  112:
		user2 = temp;
		break;
	case 113:
		user3 = temp;
		break;
	case 114:
		user4 = temp;
		break;
	case  115:
		user5 = temp;
		break;
	default:
		break;
	}
}

void card_serial_Number()
{

	card_charge();
	cout << "\n Enter this serial number ---> ";
	if (Userchoice == '1') { cout << srialnumbers[0]; }
	else if (Userchoice == '2') { cout << srialnumbers[1]; }
	else { cout << srialnumbers[2]; } cout << "\n\n ";
	cin >> serialNumber;
	if (Userchoice == '1' && serialNumber == srialnumbers[0])
	{
		balance = balance + 5;
		flex = flex + 20;

	}
	else if (Userchoice == '2' && serialNumber == srialnumbers[1])
	{
		balance = balance + 10;
		flex = flex + 40;
	}
	else if (Userchoice == '3' && serialNumber == srialnumbers[2])
	{
		balance = balance + 50;
		flex = flex + 200;
	}
	else {
		cout << "\nPlease Enter serial number as it writen\n";
		this_thread::sleep_for(3s);
		card_serial_Number();
	}

}
void card_charge()
{

	system("cls");
	cout << "  \nPlease enter the order of the card that you want to charge from the list \n\n  1 - 5 LE\n\n  2 - 10 LE\n\n  3 - 50 LE \n\n To back enter number 0 ...\n\n\t";
	if (!FlexPackage) { cout << "\nYour balance : " << balance << " LE\n\n"; }
	else if (FlexPackage) { cout << "\nYour flexes : " << flex << "\n\n"; }

}
void Balance_Recharge() {

	card_charge();
	cin >> Userchoice;
	switch (Userchoice)
	{
	case '1':
		card_serial_Number();
		card_charge();
		Balance_Recharge();
		break;
	case '2':
		card_serial_Number();
		card_charge();
		Balance_Recharge();
		break;
	case '3':
		card_serial_Number();
		card_charge();
		Balance_Recharge();
		break;
	case '0':
		User_Options();
	default:
		cout << "Please choose one of the available options";
		this_thread::sleep_for(2s);
		card_charge();
		Balance_Recharge();
	}
}

void Package_Type()
{

	system("cls");
	cout << "  \nPlease enter the order of the Package type that you want from the list \n\n  1 - flex packge \n\n  2 - ordinary packge \n\n  To back enter number ( 0 )  \n\n  ";
	if (!FlexPackage) { cout << "  Your balance : " << balance << " LE\n\n"; }
	else if (FlexPackage) { cout << "  Your flexes : " << flex << "\n\n"; }
	cin >> Userchoice;
	switch (Userchoice)
	{
	case '1':
		cout << "You are now on the Flex package \n you should recharge your balance if your flexes over ";
		FlexPackage = 1;
		this_thread::sleep_for(4s);
		Package_Type();
	case '2':
		cout << "You are now on the ordinary package ";
		FlexPackage = 0;
		this_thread::sleep_for(2s);
		Package_Type();
	case '0':
		User_Options();
	default:
		cout << "Please choose one of the available options";
		this_thread::sleep_for(2s);
		Package_Type();
	}
}

void Balance_Transfer_Value()
{
	system("cls");
	cout << "  \n Hi " << temp.name;
	cout << "  \nYour balance : " << balance << " LE\n\n";
	cout << "  Your flexes : " << flex << "\n";
	cout << "\n\nPlease enter the value you want to transfer \n insert (0) to back   ";
	//user must enter only numbers
	cin >> BalanceTransfer;
	if (BalanceTransfer == 0 )
	{
		User_Options();
	}
	if ((BalanceTransfer + 0.25) > balance)
	{
		cout << "\n You cannot transfer balance more than your balance ";
		this_thread::sleep_for(3s);
		Balance_Transfer_Value();
	}
}

void Balance_Transfer_Vodafone_Mange()
{
	cin >> Userchoice;
	switch (Userchoice)
	{
	case '1':
		if (temp.ID == user1.ID)
		{
			cout << "\n Please choose any number except yours ";
			Balance_Transfer_Vodafone_Mange();
		}
		else
		{
			temp.Vodafonebalance =( balance - BalanceTransfer )- 0.25;
			balance = balance - BalanceTransfer - 0.25;
			flex = balance * 4;
			user1.Vodafonebalance = user1.Vodafonebalance + BalanceTransfer;
			user1.Vodafoneflex += (BalanceTransfer * 4);
			Balance_Transfer_Vodafone();
		}
	case '2':
		if (temp.ID == user2.ID)
		{
			cout << "\n Please choose any number except yours ";
			Balance_Transfer_Vodafone_Mange();
		}
		else
		{
			temp.Vodafonebalance = (balance - BalanceTransfer )- 0.25;
			balance = balance - BalanceTransfer - 0.25;
			flex = balance * 4;
			user2.Vodafonebalance = user2.Vodafonebalance + BalanceTransfer;
			user2.Vodafoneflex += (BalanceTransfer * 4);
			Balance_Transfer_Vodafone();
		}
	case '3':
		if (temp.ID == user3.ID)
		{
			cout << "\n Please choose any number except your ";
			Balance_Transfer_Vodafone_Mange();
		}
		else
		{
			temp.Vodafonebalance =( balance - BalanceTransfer )- 0.25;
			balance = balance - BalanceTransfer - 0.25;
			flex = balance * 4;
			temp.Vodafoneflex = flex;
			user3.Vodafonebalance = user3.Vodafonebalance + BalanceTransfer;
			user3.Vodafoneflex += (BalanceTransfer * 4);
			Balance_Transfer_Vodafone();
		}
	case '4':
		if (temp.ID == user4.ID)
		{
			cout << "\n Please choose any number except your ";
			Balance_Transfer_Vodafone_Mange();
		}
		else
		{
			temp.Vodafonebalance =( balance - BalanceTransfer) - 0.25;
			balance = balance - BalanceTransfer - 0.25;
			flex = balance * 4;
			user4.Vodafonebalance = user4.Vodafonebalance + BalanceTransfer;
			user4.Vodafoneflex += (BalanceTransfer * 4);
			Balance_Transfer_Vodafone();
		}
	case '5':
		if (temp.ID == user5.ID)
		{
			cout << "\n Please choose any number except your ";
			Balance_Transfer_Vodafone_Mange();
		}
		else
		{
			temp.Vodafonebalance = (balance - BalanceTransfer )- 0.25;
			balance = balance - BalanceTransfer - 0.25;
			flex = balance * 4;
			user5.Vodafonebalance = user5.Vodafonebalance + BalanceTransfer;
			user5.Vodafoneflex += (BalanceTransfer * 4);
			Balance_Transfer_Vodafone();
		}
	case '0':
		User_Options();
	default:
		cout << "\n please insert a valid choies ";
		Balance_Transfer_Vodafone_Mange();
	}
}
void Balance_Transfer_Vodafone() {
	system("cls");
	Saving_Data();
	if (TelNumber == temp.telVodafone) {
		Balance_Transfer_Value();
		cout << " \n\nPlease enter the order of the user that you want to Transfer Balance to him from the list \n\n ";
		string  usersname[] = { user1.name,user2.name, user3.name, user4.name, user5.name };
		string telnumber[] = { user1.telVodafone, user2.telVodafone, user3.telVodafone , user4.telVodafone, user5.telVodafone };
		for (int i = 0; i < 5; i++)
		{
			cout << "\n" << "  " << i + 1 << " - " << usersname[i] << " ---> " << telnumber[i] << "\n";
		}

		cout << "\n to back enter number --> 0  ";
		Balance_Transfer_Vodafone_Mange();
	}
}

void Balance_Transfer_Etislate_Mange() {

	cin >> Userchoice;
	switch (Userchoice)
	{
	case '1':
		if (temp.ID == user1.ID)
		{
			cout << "\n Please choose any number except your ";
			Balance_Transfer_Etislate_Mange();
		}
		else {
			balance =( balance - BalanceTransfer )- 0.25;
			flex = balance * 4;
			user1.Etisalatbalance = user1.Etisalatbalance + BalanceTransfer;
			user1.Etisalatflex += (BalanceTransfer * 4);
			Balance_Transfer_Etislate();
		}
	case '2':
		if (temp.ID == user2.ID)
		{
			cout << "\n Please choose any number except your ";
			Balance_Transfer_Etislate_Mange();
		}
		else
		{
			balance =( balance - BalanceTransfer )- 0.25;
			flex = balance * 4;
			user2.Etisalatbalance = user2.Etisalatflex + BalanceTransfer;
			user2.Etisalatflex += (BalanceTransfer * 4);
			Balance_Transfer_Etislate();
		}
	case '3':
		if (temp.ID == user3.ID)
		{
			cout << "\n Please choose any number except your ";
			Balance_Transfer_Etislate_Mange();
		}
		else
		{
			balance =( balance - BalanceTransfer )- 0.25;
			flex = balance * 4;
			user3.Etisalatbalance = user3.Etisalatbalance + BalanceTransfer;
			user3.Etisalatflex += (BalanceTransfer * 4);
			Balance_Transfer_Etislate();
		}
	case '0':
		User_Options();
	default:
		cout << "\n please insert a valid answer ";
		Balance_Transfer_Etislate_Mange();
	}
}
void Balance_Transfer_Etislate() {

	system("cls");
	Saving_Data();
	if (TelNumber == temp.telEtisalat) {
		Balance_Transfer_Value();
		cout << " \n\nPlease enter the order of the user that you want to Transfer Balance to him from the list \n\n ";

		string  usersname[] = { user1.name,user2.name, user3.name };
		string telnumber[] = { user1.telEtisalat, user2.telEtisalat, user3.telEtisalat };
		for (int i = 0; i < 3; i++)
		{
			cout << "\n" << "  " << i + 1 << " - " << usersname[i] << " ---> " << telnumber[i] << "\n";
		}


		cout << "\n to back enter number --> 0  ";
		Balance_Transfer_Etislate_Mange();
	}
}

void Balance_Transfer_Orange_Mange()
{

		cin >> Userchoice;
		switch (Userchoice)
		{
		case '1':
			if (temp.ID == user1.ID)
			{
				cout << "\n Please choose any number except your ";
				Balance_Transfer_Orange_Mange();
			}
			else {
				balance =( balance - BalanceTransfer )- 0.25;
				flex = balance * 4;
				user1.Orangebalance = user1.Orangebalance + BalanceTransfer;
				user1.Orangeflex += (BalanceTransfer * 4);
				Balance_Transfer_Orange();
			}
		case '2':
			if (temp.ID == user3.ID)
			{
				cout << "\n Please choose any number except your ";
				Balance_Transfer_Orange_Mange();
			}
			else
			{
				balance =( balance - BalanceTransfer )- 0.25;
				flex = balance * 4;
				user2.Orangebalance = user2.Orangebalance + BalanceTransfer;
				user2.Orangeflex += (BalanceTransfer * 4);
				Balance_Transfer_Orange();
			}
		case '3':
			if (temp.ID == user5.ID)
			{
				cout << "\n Please choose any number except your ";
				Balance_Transfer_Orange_Mange();
			}
			else
			{
				balance =( balance - BalanceTransfer )- 0.25;
				flex = balance * 4;
				user3.Orangebalance = user3.Orangebalance + BalanceTransfer;
				user3.Orangeflex += (BalanceTransfer * 4);
				Balance_Transfer_Orange();
			}
		case '0':
			User_Options();
		default:
			cout << "\n please insert a valid answer ";
			Balance_Transfer_Orange_Mange();
		}

}
void Balance_Transfer_Orange()
{
	system("cls");
	Saving_Data();
	if (TelNumber == temp.telOrange)
	{
		Balance_Transfer_Value();
		cout << " \n\nPlease enter the order of the user that you want to Transfer Balance to him from the list \n\n ";

		string  usersname[] = { user1.name,user3.name, user5.name };
		string telnumber[] = { user1.telOrange, user3.telOrange, user5.telOrange };
		for (int i = 0; i < 3; i++)
		{
			cout << "\n" << "  " << i + 1 << " - " << usersname[i] << " ---> " << telnumber[i] << "\n";
		}

		cout << "\n to back enter number --> 0  ";
		Balance_Transfer_Orange_Mange();
	}

}

void User_Options_Choises()
{

	cin >> Userchoice;
	switch (Userchoice)
	{
	case '1':
		if (balance == 0)
		{
			cout << "Sorry, your balance has been over Please recharge your balance first";
			User_Options_Choises();
		}
		else
		{
			balance = balance - 0.25;
			flex = flex - 1;
			this_thread::sleep_for(2s);
			User_Options();
		}
	case '2':
		if (balance == 0)
		{
			cout << "Sorry, your balance has been over Please recharge your balance first";
			User_Options_Choises();
		}
		else
		{
			balance = balance - 0.25;
			flex = flex - 1;
			this_thread::sleep_for(2s);
			User_Options();
		}
	case '3':
		Balance_Transfer_Vodafone();
		Balance_Transfer_Etislate();
		Balance_Transfer_Orange();
		User_Options();
	case '4':
		Balance_Recharge();
		User_Options();
	case '5':
		Package_Type();
		User_Options();
	case'6':
		Saving_Data();
		Choose_Network();
	default:
		cout << "\nPlease insert a valid answer\n";
		User_Options_Choises();
		break;
	}
}
void User_Options() 
{

	system("cls");
	Saving_Data();
	cout << "\n  \t  " << temp.name << " Account \n";
	cout << "your ID : " << temp.ID << "\nyour E-mail : " << temp.E_mail << "\nyour phone number : " << TelNumber;
	if (!FlexPackage) { cout << "\nYour balance : " << balance << " LE\n\n"; }
	else if (FlexPackage) { cout << "\nYour flexes : " << flex << "\n\n"; }
	cout << "\n   Chose the process you want to perform by entering it's order from the list : \n\n";
	if (!FlexPackage) { cout << "  Call, message and balance transfer  costed .25 LE" << "\n\n"; }
	else if (FlexPackage) { cout << "  Call, messageand balance transfer costed 1 flex " << "\n\n"; }
	cout << " 1 - Make a call \n\n 2 - Send a message \n\n 3 - Balance transfer \n\n 4 - Balance recharge \n\n 5 - Change package type \n\n 6 - Choose another line \n\n\t";
	User_Options_Choises();

}

void Sign_In() 
{

	system("cls");
	cout << "  Hello " << temp.name << " please enter your password \n  to back insert (0)\n";
	cin >> userpasschek;
	if (userpasschek == "0" )
	{
		Main_Menu();
	}
	if (userpasschek != temp.password)
	{
		cout << "  \nwrong password .. Please re-enter the password  : ";
		this_thread::sleep_for(3s);
		Sign_In();
	}
}

void Choose_Network_Option()
{

		cin >> Userchoice;
		switch (Userchoice)
		{
		case '1':
			if (temp.telVodafone == "0")
			{

				cout << "    you don't have Vodafone line .. please choose another line . ";

				Choose_Network_Option();
			}
			else
			{
				TelNumber = temp.telVodafone;
				balance = temp.Vodafonebalance;
				flex = temp.Vodafoneflex;
				UserID = temp.ID;
				User_Options();
				Choose_Network();
				break;
			}
		case '2':
			if (temp.telEtisalat == "0")
			{
				cout << "    you don't have Etisalat line .. please choose another line .  ";

				Choose_Network_Option();
			}
			else
			{
				TelNumber = temp.telEtisalat;
				balance = temp.Etisalatbalance;
				flex = temp.Etisalatflex;
				UserID = temp.ID;
				User_Options();
				Choose_Network();
				break;
			}
		case '3':
			if (temp.telOrange == "0")
			{
				cout << "    you don't have Orange line .. please choose another line .  ";

				Choose_Network_Option();
			}
			else
			{
				TelNumber = temp.telOrange;
				balance = temp.Orangebalance;
				flex = temp.Orangeflex;
				UserID = temp.ID;
				User_Options();
				Choose_Network();
				break;
			}
		case '0':
			Main_Menu();
		default:
			cout << "\n  please choose valid line ... ";
			Choose_Network_Option();
			break;
		}


}
void Choose_Network() {

		system("cls");
		cout << "\n  \t  " << temp.name << " Account \n";
		cout << "your ID : " << temp.ID << "\nyour E-mail : " << temp.E_mail << "\n\n";
		cout << "\n   Choose the line that you want to manage";
		cout << "\n  1 - Vodafone  \n  2 - Etisalat  \n  3 - Orange \n  0 - To back and choose anther account ";
		// case of user choose a line that did not have He will be told that he chooses another line 
		Choose_Network_Option();
	}

void Main_Menu()
{
	system("cls");// system("cls") is to clear window 
	cout << "  Hello sir .... \n \n\t please choose your account name by entering it's order in the list  \n ";
	string  usersname[] = { user1.name,user2.name, user3.name, user4.name, user5.name };
	for (int i = 0; i < 5; i++)
	{
		cout << "\n" << "  " << i + 1 << " - " << usersname[i] << "\n";
	}

	Main_Menu_Options();
}
void Main_Menu_Options()
{
		cin >> Userchoice;

		switch (Userchoice)
		{
		case '1':
			temp = user1;
			Sign_In();
			Choose_Network();
			Main_Menu();
		case '2':
			temp = user2;
			Sign_In();
			Choose_Network();
			Main_Menu();
		case '3':
			temp = user3;
			Sign_In();
			Choose_Network();
			Main_Menu();
		case '4':
			temp = user4;
			Sign_In();
			Choose_Network();
			Main_Menu();
		case '5':
			temp = user5;
			Sign_In();
			Choose_Network();
			Main_Menu();
		default:
			cout << "  \nPlease enter a number that is already in the list : ";
			Main_Menu_Options();
	    }
}