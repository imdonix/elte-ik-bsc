using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace WoW
{
    static class Extension
    {
        public static void ToConsole<T>(this IEnumerable<T> input, string str)
        {
            Console.WriteLine("*** BEGIN " + str);
            foreach (T item in input)
            {
                Console.WriteLine(item.ToString());
            }
            Console.WriteLine("*** END " + str);
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            XDocument doc = XDocument.Load("war_of_westeros.xml");
            //Q1
            var q1 = doc.Descendants("house").Select(node => node.Value).Distinct();
            Console.WriteLine("number of houses:" + q1.Count());

            q1.ToConsole("Q1 - Houses");

            //q2
            string type = "ambush";
            var q2 = doc.Descendants("battle")
                        .Where(b => b.Element("type").Value == type)
                        .Select(bottle => bottle.Element("name").Value);

            IEnumerable<string> q2b = 
                      from node in doc.Descendants("battle")
                      where node.Element("type").Value == type
                      select node.Element("name").Value;

            q2b.ToConsole("Q2 - Ambushes");

            // q3
            IEnumerable<string> q3 = from battle in doc.Descendants("battle")
                                     where battle.Element("outcome").Value == "defender" &&
                                           (int)battle.Element("majorcapture") > 0
                                     select battle.Element("name").Value;
            Console.WriteLine("q3: number of battles: " + q3.Count());
            q3.ToConsole("Q3");

            //q4
            var q4 = from battle in doc.Descendants("battle")
                     where battle.Element(battle.Element("outcome").Value)
                                 .Descendants("house")
                                 .Select(h => h.Value).Contains("Stark")

                     select battle.Element("name").Value;
            q4.ToConsole("Q4 - StarkWonBottles");

            //q5
            var q5 = from battle in doc.Descendants("battle")
                     let attackerSize = battle.Element("attacker").Elements("house").Count()
                     let defenderSize = battle.Element("defender").Elements("house").Count()
                     let sumNum = attackerSize + defenderSize
                     where sumNum > 2
                     orderby sumNum descending
                     select new
                     {
                         BattleName = battle.Element("name").Value,
                         HousesCount = sumNum,
                         Region = battle.Element("region").Value
                     };
            q5.ToConsole("Q5 - battle with more than 2 houses");

            //q6
            var q6 = from battle in doc.Descendants("battle")
                     group battle by battle.Element("region").Value into grp
                     let grpCount = grp.Count()
                     orderby grpCount descending
                     select new
                     {
                         Count = grpCount,
                         Region = grp.Key
                     };
            q6.Take(3).ToConsole("Q6 - BattlesPerRegion");

            //q7
            var q7 = q6.FirstOrDefault();

            Console.WriteLine("Q7 - firstordedault");
            Console.WriteLine(q7);

            //q8
            var q8 = from region in q6
                     join battle in q5 on region.Region equals battle.Region
                     select new
                     {
                         Battle = battle.BattleName,
                         Regio = battle.Region,
                         NumBattle = region.Count
                     };
            q8.ToConsole("Q8 - AfterJoin");

            //q9
            var q9 = from battle in doc.Descendants("battle")
                     let winner = battle.Element("outcome").Value
                     let winnerHouses = battle.Element(winner).Elements("house").Select(h => h.Value)
                     from house in winnerHouses
                     group house by house into grp
                     orderby grp.Count() descending
                     select new
                     {
                         House = grp.Key,
                         BattlesWon = grp.Count()
                     };

            q9.ToConsole("Q9 - won by house");

            // Q10 = BattleWithLargestArmy
            int maxSize = doc.Descendants("size").Max(node => (int)node);
            var q10 = from node in doc.Descendants("size")
                     where (int)node == maxSize
                     select new { Battle = node.Parent.Parent.Element("name").Value, Size = maxSize, King = node.Parent.Element("king").Value };
            q10.ToConsole("Q10 - LargestArmy");

            // Q11 = commander with most number of attacks
            var q11 = from attackerNode in doc.Descendants("attacker")
                      from commander in attackerNode.Descendants("commander")
                      group commander by commander.Value into grp
                      orderby grp.Count() descending
                      select new { AttackerCommander = grp.Key, Count = grp.Count()  };
            q11.Take(3).ToConsole("Q11 - AttackerCommanders");

          Console.ReadLine();
        }
    }
}
