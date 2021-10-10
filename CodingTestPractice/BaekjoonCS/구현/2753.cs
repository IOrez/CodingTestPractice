using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekjoonCS.구현
{
    class _2753
    {
        int _year;
        private void Init()
        {
            _year = int.Parse(Console.ReadLine());
        }
        public void Solution()
        {
            Init();
            int result = 0;
            if ((_year % 4 == 0) && ((_year % 400 == 0) || _year % 100 != 0)) result = 1;
            Console.WriteLine(result);
        }
    }
}
