#include <iostream>
#include <thread>
#include <random>
#include <string>
#include <print>
#include <array>
#include <algorithm>

using namespace std;

class Racer {
private:
    string name;
    int total;

public:
    Racer(string n) : name(n), total(0) {}

    void run() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dist(1, 1000);

        for (int i = 0; i < 100; i++) {
            total += dist(gen);
        }
    }

    int getTotal() const {
        return total;
    }

    string getName() const {
        return name;
    }
};

int main() {
    // Usando std::array
    array<Racer, 10> racers = {
        Racer("Racer1"), Racer("Racer2"), Racer("Racer3"),
        Racer("Racer4"), Racer("Racer5"), Racer("Racer6"),
        Racer("Racer7"), Racer("Racer8"), Racer("Racer9"),
        Racer("Racer10")
    };

    // Threads
    thread t1(&Racer::run, &racers[0]);
    thread t2(&Racer::run, &racers[1]);
    thread t3(&Racer::run, &racers[2]);
    thread t4(&Racer::run, &racers[3]);
    thread t5(&Racer::run, &racers[4]);
    thread t6(&Racer::run, &racers[5]);
    thread t7(&Racer::run, &racers[6]);
    thread t8(&Racer::run, &racers[7]);
    thread t9(&Racer::run, &racers[8]);
    thread t10(&Racer::run, &racers[9]);

    // Joins
    t1.join(); t2.join(); t3.join(); t4.join(); t5.join();
    t6.join(); t7.join(); t8.join(); t9.join(); t10.join();

    // Ordenar con std::sort
    sort(racers.begin(), racers.end(),
         [](const Racer& a, const Racer& b) {
             return a.getTotal() > b.getTotal();
         });




    std::println("\nEl ganador es: {} con {} puntos",racers.front().getName(), racers.front().getTotal());
    return 0;
}
