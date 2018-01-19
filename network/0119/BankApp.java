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
} // end class BankAccount


////////////////////////////////////////////////////////////////
class BankApp
{
  public static void main(String[] args)
  {
    BankAccount ba1 = new BankAccount(100.00); 
    BankAccount Ba2 = new BankAccount(100.00);


    System.out.print("Before transactions, ");
    ba1.display();
    ba2.display();

    System.out.println("Transfer ba1 -> ba2");


    System.out.print("After transactions, ");
    ba1.display();
    ba2.display();
  } 
}
