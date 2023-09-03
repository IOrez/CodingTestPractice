using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekjoonCS
{
    class _2490
    {
        int[] _table = Enumerable.Repeat<int>(0, 4).ToArray();
        private void Init()
        {
            String[] input = Console.ReadLine().Split(' ');
            for (int i = 0; i < input.Length; ++i)
                _table[i] = int.Parse(input[i]);
        }
        public void Solution()
        {
            for (int i = 0; i < 3; ++i)
            {
                Init();
                int cnt = 0;
                foreach (int value in _table)
                    cnt += value;

                char res = 'A';
                switch (cnt)
                {
                    case 0: res = 'D'; break;
                    case 1: res = 'C'; break;
                    case 2: res = 'B'; break;
                    case 3: res = 'A'; break;
                    case 4: res = 'E'; break;
                }

                Console.WriteLine(res.ToString());
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            _1926 problem = new _1926();
            problem.Solution();
        }
    }
}
