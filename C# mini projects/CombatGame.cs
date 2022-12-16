using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using static System.Math;
namespace ROCKPAPERSCISSORS
{
    class Program
    {
        static void Main(string[] args)
        {

            int playerHp = 40;
            int enemyHP = 20;

            int playerAttack = 5;
            int enemyAttack = 7;

            int healAmount = 5;

            Random random = new Random();

            while (playerHp > 0 && enemyHP > 0)
            {
                Console.WriteLine("-- Player turn --");
                Console.WriteLine("Player HP - " + playerHp + " . Enemy HP is - " + enemyHP);
                Console.WriteLine("Enter 'a' to attack or 'h' to heal.");

                string choice = Console.ReadLine();

                if (choice == "a")
                {
                    enemyHP -= playerAttack;
                    Console.WriteLine("Player attack enemy and deals " + playerAttack + " damage!");
                }
                else
                {
                    playerHp += healAmount;
                    Console.WriteLine("Player restores " + healAmount + " health points!");
                }


                if (enemyHP > 0)
                {
                    Console.WriteLine("-- Enemy turn --");
                    Console.WriteLine("Player HP - " + playerHp + " . Enemy HP is - " + enemyHP);
                    int enemyChoice = random.Next(0, 2);

                    if (enemyChoice == 0)
                    {
                        playerHp -= enemyAttack;
                        Console.WriteLine("Enemy attack player and deals " + enemyAttack + " damage!");
                    }else
                    {
                        enemyHP += healAmount;
                        Console.WriteLine("Enemy restores " + healAmount + " health points");
                    }

                }
            }

            if (playerHp > 0){ 
            Console.WriteLine("Congrats. You won"); }
            else
            {
                Console.WriteLine("Sorry. You lost");
            }

        }
    }
}