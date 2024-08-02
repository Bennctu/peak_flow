#include <chrono>
#include <cstdlib>
#include <ctime>

class TicToc {
   public:
    TicToc() { tic(); }

    typedef std::chrono::time_point<std::chrono::steady_clock> time_point;
    void tic() { start = std::chrono::steady_clock::now(); }

    int toc() {
        end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
            .count();
    }

   private:
    time_point start, end;
};