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
            string inputPlayer, inputCPU;
            int randomInt;
            int scorePlayer = 0;
            int scoreCPU = 0;

            Console.Write("Choose beetwen ROCK, PAPER, and SCISSORS: ");
            inputPlayer = Console.ReadLine();

            Random rnd = new Random();

            randomInt = rnd.Next(1, 4);

            switch (randomInt)
            {
                case 1:
                    inputCPU = "ROCK";
                    Console.WriteLine("Computer chose ROCK");
                    if (inputPlayer == "ROCK")
                    {
                        Console.WriteLine("DRAW!!\n\n");
                    }else if (inputPlayer == "PAPER")
                    {
                        Console.WriteLine("PAPER WINS!!\n\n");
                        scorePlayer++;
                    }else if (inputPlayer == "SCISSORS")
                    {
                        Console.WriteLine("SCISSORS WINS!!\n\n");
                        scoreCPU++;
                    }
                    break;
                case 2:
                    inputCPU = "PAPER";
                    Console.WriteLine("Computer chose PAPER");
                    if (inputPlayer == "PAPER")
                    {
                        Console.WriteLine("DRAW!!\n\n");
                    }
                    else if (inputPlayer == "ROCK")
                    {
                        Console.WriteLine("PAPER WINS!!\n\n");
                        scoreCPU++;
                    }
                    else if (inputPlayer == "SCISSORS")
                    {
                        Console.WriteLine("SCISSORS WINS!!\n\n");
                        scorePlayer++;
                    }
                    break;
                case 3:
                    inputCPU = "SCISSORS";
                    Console.WriteLine("Computer chose SCISSORS");
                    if (inputPlayer == "SCISSORS")
                    {
                        Console.WriteLine("DRAW!!\n\n");
                    }
                    else if (inputPlayer == "PAPER")
                    {
                        Console.WriteLine("SCISSORS WINS!!\n\n");
                        scoreCPU++;
                    }
                    else if (inputPlayer == "ROCK")
                    {
                        Console.WriteLine("ROCK WINS!!\n\n");
                        scorePlayer++;
                    }
                    break;
                default:
                    break;
            }
        }
    }
}