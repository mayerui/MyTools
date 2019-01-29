#ifndef _UTIL_INL_
#define _UTIL_INL_

//windows下获取毫秒级时间戳
inline int getSystemTime()
{
    struct timeb t;
    ftime(&t);

    struct tm *now = localtime(&t.time);
    int second = now->tm_hour * 10000 + now->tm_min * 100 + now->tm_sec;

    return 1000 * second + t.millitm;
}

#endif
