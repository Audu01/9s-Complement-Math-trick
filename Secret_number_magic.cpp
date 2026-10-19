#include <iostream>
#include <string>
using namespace std;

class trick{
    private:
    int secretNumber;
    int userInput1;
    int userInput2;
    int magicInput1; 
    int magicInput2=0;
    int magicInput3=0;
    int magicNumArray[4];

    public:
    void setSecretNum(int& s){
        if(s>=25000 && s < 30000 ){
        secretNumber=s;
        }
    }

    void setuserinput1 (int& ui1){
        if(ui1 < 10000 && ui1 > 999 ){
            userInput1=ui1;
           // cout<<userInput1;
        }
    }


    void setuserinput2 (int& ui2){
        if(ui2 < 10000 && ui2 > 999 ){
            userInput2=ui2;
        }
    }


    int getSecretNum () const {
        return secretNumber;
    }

    int getUserInput1() const {
        return userInput1;
    }

    int getUserInput2() const {
        return userInput2;
    }


    void setMagicInput1 (){
      magicInput1 = (getSecretNum()-20000) +2;
    }


    int getMagicInput1 () const {
        return magicInput1;
    }

    void setMagicInput2(){
        
        int holder = getUserInput1();
        for(int i=3;i>=0;--i){
            magicNumArray[i]=holder % 10;
            holder/= 10;
        }

       

       
        for(int i=0; i<4; ++i){
            magicNumArray[i]=9-magicNumArray[i];
        }

        


        for(int j=0;j<4;++j){
            magicInput2 = magicInput2 * 10 + magicNumArray[j];
         }
        
    }


        void setMagicInput3(){  //is there a way to not repeat this to have only one setmagicinput function (arrays of objects???)
            int holder = getUserInput2();
            for(int i=3;i>=0;--i){
                 magicNumArray[i]=holder % 10;
                 holder/= 10;
                }

                for(int i=0; i<4; ++i){
                     magicNumArray[i]=9-magicNumArray[i];
                    }

            for(int j=0;j<4;++j){
                magicInput3=magicInput3*10+magicNumArray[j];
            }
        }

   

        int getMagicInput2 () const {
            return magicInput2;
        }


       


          int getMagicInput3 () const {
            return magicInput3;
        }


    };



    void inputSecretNum (trick& t) {    //should trick t be a  reference - fuck yea     "question 1"
        int secNum;
        cout << "what is the secret number ";
        cin >> secNum;
        if(secNum >= 25000 && secNum < 30000){
            t.setSecretNum(secNum);
        }
        else{
            inputSecretNum(t);
        }

    }


    void firstMagicNum (trick& t){
        t.setMagicInput1();
        cout <<"My number is "<<t.getMagicInput1() <<"\n" ;
    }


    void userInputFirstNum(trick& t){
        int userNum;
        cout << "Input your number ";
        cin >> userNum;
        if(userNum  < 10000 && userNum > 999){
        t.setuserinput1(userNum);
        }
        else{
            userInputFirstNum(t);
        }

    }


    void secondtMagicNum(trick& t){
        t.setMagicInput2();
        cout << "My Number is "<< t.getMagicInput2()<<"\n";
    }




     void userInputSecondNum(trick& t){
        int userNum;
        cout << "Input your number ";
        cin >> userNum;
        if(userNum  < 10000 && userNum > 999){
        t.setuserinput2(userNum);
        }
        else{
            userInputSecondNum(t);
        }

    }



     void thirdtMagicNum(trick& t){
        t.setMagicInput3();
        cout << "My Number is "<< t.getMagicInput3()<<"\n";

    }



    void sum(trick t){
        cout << "The sum is "<<t.getMagicInput1()+t.getMagicInput2()+t.getMagicInput3()+t.getUserInput1()+t.getUserInput2();
    }




int main(){
    
    trick t1;
    inputSecretNum(t1);
    firstMagicNum(t1);
    userInputFirstNum(t1);
    secondtMagicNum(t1);
    userInputSecondNum(t1);
    thirdtMagicNum(t1);
    sum(t1);

    
    
    return 0;   
} 



/* ignore this
the only way to make setMagicNum() dry is to use a counter like inside setMagicInput1() 
private:
int counter=1;
 void setMagicInput1 (){
        
      magicInput1 = (getSecretNum()-20000) +2;
      counter++;
    }


    and inside the setmagic input function 
    you should have something like 
    setmagicinput(int input, int &mg){
    *code for setting the input

    if(counter==2){
       magicNum2=mg;
       counter++;
       }

    if else (counter==3){
    magicNum3=mg;
       }
    
    }


    and you can also use it for  userInputFirstNum()



*/
 


/*
 The reason why we pass by reference  in question 1 is because 
 the object of trick is passed as the parameter therefore if we do not
 pass by reference c++ makes a copy of it, so inside the function, we are actually not directly changing the
 members of the object we are changing a copy of it which will be destroyed when the function finishes 
so to avoid this we use the reference operator.




*/