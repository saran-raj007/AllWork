import java.util.*;
class game{
    public static void main(String[] args){
        System.out.println("!!welcome to the game of mistrey numbers!!");
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the player name: ");
        String player_name=sc.next();
        System.out.print(" Hello " + player_name + " if we should start the game\nYES(1)orNO(0)\n");
        int userinput=sc.nextInt();
        if(userinput==1){
            
            int count=0;
            System.out.println("let's start!!");
            Random rn=new Random();
            int rnumber=rn.nextInt(100);
            do{
            System.out.print("Enter your guessing  number: ");
            int g_number=sc.nextInt();
            if(rnumber==g_number){
                System.out.println("!!Congratulation your guess is correct!!");
                break;
            }
            else{
                count++;
                System.out.println("!!hint!!");
                if(g_number>rnumber){
                   System.out.println("Your guessing number is grater than the mystery number");
                }
                else{
                    System.out.println("Your guessing number is less than the mystery number");
                }
                System.out.println("!!TRY agin!!");
            }
            }while(count<5);
            if(count>=5){
                System.out.println("!!your chance is over!!");
                System.out.println("The mistrey number is: "+ rnumber);
                System.out.println("!!Thank you for playing!!");
            }

        }
        else{
            System.out.print("!!Thank you for playing!!");

        }
    }
}
