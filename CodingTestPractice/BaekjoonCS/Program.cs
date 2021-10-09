using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekjoonCS
{
    class _10808
    {
        String input;
        int[] Cnt;

        private void Init()
        {
            Cnt = Enumerable.Repeat((int)0, 'z' - 'a' + 1).ToArray();
            input = Console.ReadLine();
        }

        public void Solution()
        {
            Init();
            foreach (char c in input)
                Cnt[c - 'a']++;
            foreach (int i in Cnt)
                Console.Write(i + " ");

        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            _10808 problem = new _10808();
            problem.Solution();
        }
    }
}
