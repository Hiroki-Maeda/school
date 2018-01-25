import java.io.*; // for I/O
////////////////////////////////////////////////////////////////
class BankAccount
{
  private double balance; // account balance


  public BankAccount(double openingBalance) // constructor
  {
    balance = openingBalance;
  }


  public void deposit(double amount) // makes deposit
  {
    balance = balance + amount;
  }


  public void withdraw(double amount) // makes withdrawal
  {
    balance = balance - amount;
  }


  public void display() // displays balance
  {
    System.out.println("balance=" + balance);
  }
  public void transfer(BankAccount ba, double amount){
      balance -= amount;
      ba.balance += amount;
  }
} // end class BankAccount


////////////////////////////////////////////////////////////////
class BankApp
{
  public static void main(String[] args)
  {
    BankAccount ba1 = new BankAccount(100.00); 
    BankAccount ba2 = new BankAccount(100.00);
    double transferAmount = 80;

    System.out.print("Before transactions ba1, ");
    ba1.display();
    System.out.print("Before transactions Ba2, ");
    ba2.display();
    
    System.out.println("Transfer ba1 -> ba2 amount = "+transferAmount);
    ba1.transfer(ba2, transferAmount);

    System.out.print("After transactions ba1, ");
    ba1.display();
    System.out.print("After transactions ba2, ");
    ba2.display();
  } 
}

/***************************************************
Before transactions ba1, balance=100.0
Before transactions Ba2, balance=100.0
Transfer ba1 -> ba2 amount = 80.0
After transactions ba1, balance=20.0
After transactions ba2, balance=180.0
***************************************************/
