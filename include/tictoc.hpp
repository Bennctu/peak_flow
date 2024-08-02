#include <chrono>

class TicToc {
   public:
    /// @brief construct a instance and timer starts
    TicToc() { tic(); }

    typedef std::chrono::time_point<std::chrono::steady_clock> time_point;
    void tic() { start = std::chrono::steady_clock::now(); }

    /// @brief timer ends and compute the duration time
    /// @return duration time (nanosecond)
    int toc() {
        end = std::chrono::steady_clock::now();
        return std::chrono::duration_cast<std::chrono::nanoseconds>(end - start)
            .count();
    }

   private:
    time_point start, end;
};