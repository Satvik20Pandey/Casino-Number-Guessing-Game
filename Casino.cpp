#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


string hint_box = "\n********HINTS BOX********\n1. HIGHER OR LOWER.\n2. EVEN OR ODD.\n3. DIVISIBILITY TEST.\n4. SUM OF DIGITS.\n5. PRODUCT OF DIGITS.\n6. PRIME OR COMPOSITE\n*************************\n";


void rules(){
    cout<<"\t\t\t========== GAME RULES! ==========\n"<<endl;
    cout<<"1. A random number will be selected between 1 and 50 (both included)."<<endl;
    cout<<"2. You will have 5 chances to guess the number."<<endl;
    cout<<"3. You will recieve 2 times the betting amount if you guess the correct number in 1st try."<<endl;
    cout<<"4. Similarly, you will recieve 1.5 times, 1 times, 0.75 times and 0.5 times the betting amount if you guess the correct number in 2, 3, 4 and 5 tries respectively."<<endl;
    cout<<"5. If you are not able to guess the number in 5 turns you will loose all your betting amount."<<endl;
    cout<<"6. After every incorrect guess you can choose one of the hints of your choice."<<endl;
}

int main()
{
  
    cout<<"\n\n\t\t========= WELCOME TO CASINO NUMBER GUESSING GAME =========\n\n"<<endl;

    
    rules();

   
    int balance;
    int bet_amount;
    char choice;

 
    cout<<"\nEnter the starting balance to play game: ";
    cin>>balance;


    do{
      
        cout<<"\nYour current balance is Rs."<<balance<<endl;;
        do{            
            cout<<"Enter amount to bet: ";            
            cin>>bet_amount;

      
            if(bet_amount > balance)                
            cout<<"\nBetting balance can't be more than current balance!\n"
            <<"\nRe-enter balance\n";        
        }

        while(bet_amount > balance);

      
        balance -= bet_amount;
        cout<<"Balance left: Rs."<<balance<<"\n"<<endl;
        
    
        int min = 1, max = 50;
        srand(time(0));
        int num = 1 + (rand() % 50);

  
        int count = 1;
        while (count <= 5){

        
            int guess;
            cout<<"Guess the number: ";
            cin>>guess;

           
            if (num == guess){
                cout<<"\nCONGRATULATIONS!!!! U have guessed the right number in "<<count<<" turn(s)"<<endl;
                break;
            }
           
            else{
              
                if (count == 5){
                    cout<<"\nGAME OVER!! The number was: "<<num<<endl;;
                    cout<<"Better luck next time."<<endl;
                    count++;
                    break;
                }
             
                else{

       
                    cout<<"\nOops, that was wrong unfortunately, No worries, we got some hints for you."<<endl;
                    cout<<"You still have "<<5-count<<" tries left."<<endl;
                    cout<<hint_box<<endl;
                    
         
                    int hint;
                    cout<<"Enter the number of hint you want: ";
                    cin>>hint;

                   
                    if (hint == 1){
                        if (num > guess){
                            cout<<"\nYou guessed too small!!\n"<<endl;
                        }
                        else{
                            cout<<"\nYou guessed too high!!\n"<<endl;
                        }
                    }
                   
                    else if (hint == 2){
                        if (guess % 2 == 0){
                            cout<<"\nNumber is even!\n"<<endl;
                        }
                        else{
                            cout<<"\nNumber is odd!\n"<<endl;
                        }
                    }
             
                    else if (hint == 3){
                        int x;
                        cout<<"\nEnter the number for which you want to check the divisibility: ";
                        cin>>x;
                        if (guess % x == 0){
                            cout<<"The number is divisible by "<<x<<"!\n"<<endl;
                        }
                        else{
                            cout<<"The number is not divisible by "<<x<<"\n"<<endl;
                        }
                    }
                  
                    else if (hint == 4){
                        int temp = num, sum = 0;
                        while (temp != 0) {
                            int d = temp % 10;
                            temp /= 10;

                            sum += d;
                        }
                        cout<<"Sum of the digits of the number is: "<<sum<<"\n"<<endl;
                    }
                  
                    else if (hint == 5){
                        int temp = num, product = 1;
                        while (temp != 0){
                            int d = temp % 10;
                            temp /= 10;
                            product *= d;
                        }
                        cout<<"\nProduct of digits of the number is "<<product<<"\n"<<endl;
                    }
                  
                    else if (hint == 6){
                        int i, temp=0;

                        for(i=2;i<num;i++)
                        {
                            if(num%i==0)
                            {
                                temp++;
                                break;
                            }
                        }
                        if (temp == 0){
                            cout<<"\nThe number is Prime!!\n"<<endl;
                        }
                        else{
                            cout<<"\nThe number is composite!!\n"<<endl;
                        }
                    }
                    else{
                        cout<<"INVALID HINT, As a Penalty you lose a Hint"<<endl;
                    }
                }
            }
            if (count == 4){
                cout<<"Warning!! This is your last try!!"<<endl;
            }
            count++;
        }
    
        if (count == 1){
            balance += int(bet_amount*2);
        }


       
        else if (count == 2){
            balance += int(bet_amount*1.5);
        }
        else if (count == 3){
            balance += bet_amount;
        }
       
        else if (count == 4){
            balance += int(bet_amount*0.75);
        }
    
        else if (count == 5){
            balance += int(bet_amount*0.5);
        }
  


        if (balance == 0){
            cout<<"\nYou have no money left to play."<<endl;;
            break;
        }
   
        cout<<"\nDo you want to play again (y/n)? ";
        cin>>choice;
    }
    while((choice == 'Y') || (choice == 'y'));

  
    if (balance == 0){
        cout<<"\nThanks for playing the game!!"<<endl;
    }
    else{
        cout<<"\nThanks for playing the game!! Please collect your balance amount of Rs."<<balance<<"\n"<<endl;
    }
    return 0;
}
