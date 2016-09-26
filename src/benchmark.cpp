#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>
#include <chrono>
#include <string>
#include <time.h>
#include <math.h>

#include "user.h"
#include "tests.h"
#include "globals.h"

using namespace std;

ulong benchmark_save(int passes, bool useBuffer, ostringstream &output, ulong sleep, ulong sleepStep)
{

    // http://stackoverflow.com/questions/22387586/measuring-execution-time-of-a-function-in-c
    chrono::steady_clock::time_point tInner_s;
    chrono::steady_clock::time_point tInner_e;
    chrono::steady_clock::time_point tOuter_s;
    chrono::steady_clock::time_point tOuter_e;
    chrono::steady_clock::time_point tOffset_e;

    ulong durationInner = 0;
    ulong avgTime = 0;

    chrono::duration<ulong, std::nano> totalTimeDur;

    // Generate data and save it
    User UserDataSave;
    UserDataSave = set_user_data();


    //http://www.cplusplus.com/forum/unices/3440/
    struct timespec timeOut,remains;

    timeOut.tv_sec = 0;
    timeOut.tv_nsec = sleep;

    const ulong MAX_SLEEP = 999999999;
    struct timespec timeOut2,remains2;

    timeOut.tv_sec = 0;
    timeOut.tv_nsec = MAX_SLEEP;


    int extraSleeps = 0;

    // say sleep is 1000000000. that is 1 ns too loading
    // need to sleep for max and remainder

    /*
    1 s = 1000 ms
    1 ms = 1000 us
    1 us = 1000 ns

    1 ns = 1 * 10^-9 s
    */
    tOuter_s = chrono::steady_clock::now();

    for (int i = 1; i < (passes + 1); i++)
    {
        tInner_s = chrono::steady_clock::now();
        UserDataSave.save(useBuffer);
        tInner_e = chrono::steady_clock::now();

        nanosleep(&timeout, &remains);

        for (int j = 0; j < extraSleeps; j++)
            nanosleep(&timeOut2, &remains2);

        tOffset_e = chrono::steady_clock::now();
        totalTimeDur += tInner_e - tInner_s;

        durationInner = chrono::duration_cast<chrono::microseconds>(tInner_e - tInner_s).count();

        avgTime = chrono::duration_cast<chrono::microseconds>(totalTimeDur / i).count();

        output << i << ", " << durationInner << ", " << avgTime << "\n";

        /*
        if the new sleep value is larger than MAX_SLEEP
        then get the difference.
        increase ExtraSleeps
        set the sleep to the diff
        */

        // Need to add sleep to

        if ((sleep + sleepStep) > MAX_SLEEP)
        {
            // Get difference between the new sleep and the max sleep
            sleep = (sleep + sleepStep) - MAX_SLEEP;
            extraSleeps++;
        }
        else
        {
            sleep += sleepStep;
        }

        timeout.tv_nsec = sleep;

    }

    output << "0, " << "0, " << avgTime << "\n";

    //tOuter_e = chrono::steady_clock::now();

    //duration = chrono::duration_cast<chrono::microseconds>(((t3 - t1) / passes)).count();

    // std::cout << "--- BENCHMARK: save() ----\n";
    // cout << "Buffer = " << boolalpha << useBuffer << "\n";
    // std::cout << "Passes = " << passes << "\n";
    // std::cout << "Time: " << duration << " microseconds\n";

    return avgTime;
}

int main(int argc, char *argv[])
{
    // string passesStr = "";
    int passes = 0;
    bool useBuffer = true;
    string fileName = "";
    ulong sleep = 0;
    ulong sleepStep = 0;

    //
    // string useBufferStr = "";
    // bool useBuffer = true;

    //int count = 1;

    if (argc == 6)
    {
        passes = stoi(string(argv[1]));
        useBuffer = stoi(string(argv[2]));
        fileName = argv[3];
        sleep = stol(string(argv[4]));
        sleepStep = stol(string(argv[5]));
    }
    else
        return -1;


    // if (argc != 3)
    // {
    //     for (int i = 0; i < argc; i++)
    //     {
    //         cout << i << " = " << argv[i] << endl;
    //     }
    //
    //     cout << "Usage: " << argv[0] << " <passes> <useBuffer>\n";
    // }
    // else
    // {
    //     passesStr = argv[1];
    //     passes = stoi(passesStr);
    //
    //     useBufferStr = argv[2];
    //     useBuffer = stoi(useBufferStr);
    // }





    // https://solarianprogrammer.com/2012/10/14/cpp-11-timing-code-performance/

    // cout << "steady_clock" << endl;
    // cout << chrono::steady_clock::period::num << endl;
    // cout << chrono::steady_clock::period::den << endl;
    // cout << "steady = " << boolalpha << chrono::steady_clock::is_steady << endl << endl;

    //cout << benchmark_save(passes, useBuffer);

    ostringstream resultsBuffer;
    ostringstream resultsNoBuffer;

    ofstream file(fileName);

    //resultsBuffer << "pass, time, average_time\n";

    cout << "Use buffer = " << boolalpha << useBuffer << endl;

    cout << "Avg = " << benchmark_save(passes, useBuffer, resultsBuffer, sleep, sleepStep) << " microseconds\n";
    //benchmark_save(passes, false, resultsNoBuffer);

    //cout << resultsBuffer.str();

    file << resultsBuffer.str();

    file.close();

    return 0;

}
