/**
 * @file Student.hpp
 * @brief Header file for the Student class
 *
 * This file demonstrates: 
 * - Composition (Student HAS-A array of Grades)
 * - Bracket operator []
 * - Parentheses operator ()
 * - All previous concepts (constructors, destructors, const methods, etc.)
 */

#ifndef STUDENT_HPP
#define STUDENT_HPP

#include "Grade.hpp"
#include <string>
#include <iostream>

namespace grading {

    /**
     * @brief Course struct - demonstrates composition
     * Student grades are associated with courses
     */
    struct Course {
        std::string courseName;
        std::string courseCode;
        int credits;

        Course() : courseName("Unknown"), courseCode("000"), credits(0) {}
        Course(const std::string& name, const std::string& code, int cred)
            : courseName(name), courseCode(code), credits(cred) {}
    };

    /**
     * @brief Student class representing a student with multiple grades
     */
    class Student {
    private:
        std::string name;
        std::string studentID;
        Grade* grades;
        Course* courses;
        int capacity;
        int gradeCount;
        
        // Static members
        static int totalStudentsCreated;
        static int currentStudentCount;

        /**
         * @brief Resize the grades and courses arrays
         */
        void resize();

    public:
        // ============ Constructors & Destructor ============

        /**
         * @brief Default constructor
         */
        Student();

        /**
         * @brief Parameterized constructor
         * @param name Student name
         * @param studentID Student ID
         * @param initialCapacity Initial capacity for grades (default 5)
         */
        Student(const std::string& name, const std::string& studentID, 
                int initialCapacity = 5);

        /**
         * @brief Copy constructor - deep copy
         * @param other Student to copy from
         */
        Student(const Student& other);

        /**
         * @brief Copy assignment operator - deep copy
         * @param other Student to copy from
         * @return Reference to this student
         */
        Student& operator=(const Student& other);

        /**
         * @brief Destructor
         */
        ~Student();

        // ============ Getters - Inline ============

        /**
         * @brief Get student name - const method
         * @return Student name
         */
        inline std::string getName() const {
            return name;
        }

        /**
         * @brief Get student ID - const method
         * @return Student ID
         */
        inline std::string getStudentID() const {
            return studentID;
        }

        /**
         * @brief Get number of grades - const method
         * @return Grade count
         */
        inline int getGradeCount() const {
            return gradeCount;
        }

        /**
         * @brief Get capacity - const method
         * @return Current capacity
         */
        inline int getCapacity() const {
            return capacity;
        }

        // ============ Setters - Outline ============

        void setName(const std::string& name);
        void setStudentID(const std::string& id);

        // ============ Static methods ============

        static int getTotalStudentsCreated();
        static int getCurrentStudentCount();

        // ============ Grade Management - Reference parameters ============

        /**
         * @brief Add a grade for a course
         * @param grade Grade to add
         * @param course Course associated with grade
         * @return true if successful
         */
        bool addGrade(const Grade& grade, const Course& course);

        /**
         * @brief Add a grade with just course name (overloaded)
         * @param grade Grade to add
         * @param courseName Course name
         * @return true if successful
         */
        bool addGrade(const Grade& grade, const std::string& courseName);

        /**
         * @brief Remove a grade by index
         * @param index Index of grade to remove
         * @return true if successful
         */
        bool removeGrade(int index);

        /**
         * @brief Calculate GPA - const method
         * @return GPA (0.0 - 4.0 scale)
         */
        double calculateGPA() const;

        /**
         * @brief Calculate average score - const method
         * @return Average score (0-100)
         */
        double calculateAverage() const;

        /**
         * @brief Get highest grade - const method
         * @return Reference to highest grade
         */
        const Grade& getHighestGrade() const;

        /**
         * @brief Get lowest grade - const method
         * @return Reference to lowest grade
         */
        const Grade& getLowestGrade() const;

        /**
         * @brief Count passing grades - const method
         * @return Number of passing grades
         */
        int countPassingGrades() const;

        // ============ BRACKET OPERATOR [] ============

        /**
         * @brief Access grade by index (non-const)
         * @param index Index of grade
         * @return Reference to grade at index
         */
        Grade& operator[](int index);

        /**
         * @brief Access grade by index (const version)
         * @param index Index of grade
         * @return Const reference to grade at index
         */
        const Grade& operator[](int index) const;

        /**
         * @brief Access grade by course name
         * @param courseName Name of course
         * @return Reference to grade for that course
         */
        Grade& operator[](const std::string& courseName);

        /**
         * @brief Access grade by course name (const version)
         * @param courseName Name of course
         * @return Const reference to grade for that course
         */
        const Grade& operator[](const std::string& courseName) const;

        // ============ PARENTHESES OPERATOR () ============

        /**
         * @brief Calculate weighted average with no parameters
         * Treats all grades equally
         * @return Average score
         */
        double operator()() const;

        /**
         * @brief Calculate average of first n grades
         * @param n Number of grades to include
         * @return Average of first n grades
         */
        double operator()(int n) const;

        /**
         * @brief Calculate average of grades in range [start, end)
         * @param start Start index (inclusive)
         * @param end End index (exclusive)
         * @return Average of grades in range
         */
        double operator()(int start, int end) const;

        /**
         * @brief Calculate weighted average with custom weight
         * Applies weight to specified grade index
         * @param index Index of grade to weight
         * @param weight Weight multiplier
         * @return Weighted average
         */
        double operator()(int index, double weight) const;

        // ============ ARITHMETIC OPERATORS ============

        /**
         * @brief Add bonus points to all grades
         * @param bonus Points to add to each grade
         * @return New student with adjusted grades
         */
        Student operator+(double bonus) const;

        /**
         * @brief Subtract penalty from all grades
         * @param penalty Points to subtract from each grade
         * @return New student with adjusted grades
         */
        Student operator-(double penalty) const;

        /**
         * @brief Multiply all grades by factor (curve)
         * @param factor Multiplication factor
         * @return New student with scaled grades
         */
        Student operator*(double factor) const;

        /**
         * @brief Add and assign bonus to all grades
         * @param bonus Points to add
         * @return Reference to this student
         */
        Student& operator+=(double bonus);

        /**
         * @brief Multiply and assign (curve all grades)
         * @param factor Multiplication factor
         * @return Reference to this student
         */
        Student& operator*=(double factor);

        // ============ COMPARISON OPERATORS ============

        /**
         * @brief Compare students by GPA
         * @param other Student to compare with
         * @return true if this GPA == other GPA
         */
        bool operator==(const Student& other) const;

        /**
         * @brief Compare students by GPA
         * @param other Student to compare with
         * @return true if this GPA != other GPA
         */
        bool operator!=(const Student& other) const;

        /**
         * @brief Compare students by GPA
         * @param other Student to compare with
         * @return true if this GPA < other GPA
         */
        bool operator<(const Student& other) const;

        /**
         * @brief Compare students by GPA
         * @param other Student to compare with
         * @return true if this GPA > other GPA
         */
        bool operator>(const Student& other) const;

        // ============ STREAM OPERATORS ============

        /**
         * @brief Output stream operator
         * @param os Output stream
         * @param student Student to output
         * @return Reference to output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Student& student);

        /**
         * @brief Input stream operator
         * @param is Input stream
         * @param student Student to input into
         * @return Reference to input stream
         */
        friend std::istream& operator>>(std::istream& is, Student& student);

        // ============ FRIEND FUNCTIONS ============

        /**
         * @brief Compare two students by average score
         * @param s1 First student
         * @param s2 Second student
         * @return true if s1 has higher average
         */
        friend bool compareByAverage(const Student& s1, const Student& s2);

        /**
         * @brief Check if students have same GPA
         * @param s1 First student
         * @param s2 Second student
         * @return true if same GPA
         */
        friend bool haveSameGPA(const Student& s1, const Student& s2);

        // ============ Additional Methods ============

        /**
         * @brief Print all grades with course names
         */
        void printGrades() const;

        /**
         * @brief Get course at index - const method
         * @param index Index of course
         * @return Const reference to course
         */
        const Course& getCourse(int index) const;
    };

} // namespace grading

#endif // STUDENT_HPP