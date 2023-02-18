//
// Created by szymu on 18.02.2023.
//

#ifndef GYM_APP_EXERCISE_H
#define GYM_APP_EXERCISE_H

#include <iostream>
#include <string>

class Exercise {
    friend std::ostream &operator<<(std::ostream &os, const Exercise &exercise);
private:
    std::string ExerciseName;
    double ExerciseWeight;
    unsigned int ExerciseSeries;
    unsigned int ExerciseReps;
public:
    Exercise() = default;
    Exercise(std::string name)
    : ExerciseName{name}, ExerciseWeight{0}, ExerciseSeries{0}, ExerciseReps{0} {}
    ~Exercise() = default;

    std::string getExerciseName() const;
    double getExerciseWeight() const;
    unsigned int getExerciseSeries() const;
    unsigned int getExerciseReps() const;

    void setExerciseName(std::string name);
    void setExerciseWeight(double weight);
    void setExerciseSeries(int series);
    void setExerciseReps(int reps);


};


#endif //GYM_APP_EXERCISE_H
