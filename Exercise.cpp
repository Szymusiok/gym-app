//
// Created by szymu on 18.02.2023.
//

#include "Exercise.h"
#include <iostream>
#include <string>

std::ostream &operator<<(std::ostream &os, const Exercise &exercise){
    os<<exercise.ExerciseName<<" "<<exercise.ExerciseWeight<<" "<<exercise.ExerciseSeries<<" "<<exercise.getExerciseReps()<<std::endl;
    return os;
}

std::string Exercise::getExerciseName() const {
    return ExerciseName;
}

double Exercise::getExerciseWeight() const {
    return ExerciseWeight;
}

unsigned int Exercise::getExerciseSeries() const {
    return ExerciseSeries;
}

unsigned int Exercise::getExerciseReps() const {
    return ExerciseReps;
}

void Exercise::setExerciseName(std::string name) {
    ExerciseName=name;
}

void Exercise::setExerciseWeight(double weight) {
    ExerciseWeight=weight;
}

void Exercise::setExerciseSeries(int series) {
    ExerciseSeries=series;
}

void Exercise::setExerciseReps(int reps) {
    ExerciseReps=reps;
}