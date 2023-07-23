#include <vector>
#include <string>
using namespace std;

struct Student {
    int idn;
    std::string name;
    double mark;
    bool repeater;
};

void information(const std::vector<Student>& stu, double& min, double& max, double& avg) {
    min = max = avg = 0;
    int count = 0;
    for (int i = 0; i < stu.size(); ++i) {
        Student s = stu[i];
        if (s.mark != -1 && !s.repeater) {
            min = count == 0 ? s.mark : std::min(min, s.mark);
            max = count == 0 ? s.mark : std::max(max, s.mark);
            avg += s.mark;
            ++count;
        }
    }
    if (count == 0) {
        min = max = avg = -1;
    } else {
        avg /= count;
    }
}
