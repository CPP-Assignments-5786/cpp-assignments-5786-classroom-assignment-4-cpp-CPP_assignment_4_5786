/**
 * @file Grade.hpp
 * @brief Header file for the Grade class
 *
 * This file demonstrates operator overloading: 
 * - Arithmetic operators (+, -, *, /)
 * - Comparison operators (==, !=, <, >, <=, >=)
 * - Stream operators (<<, >>)
 * - Increment/Decrement operators (++, --)
 * - Conversion operators (int, string)
 */

#ifndef GRADE_HPP
#define GRADE_HPP

#include <string>
#include <iostream>

namespace grading {

    /**
     * @brief Grade class representing a single grade/score
     * Demonstrates:  arithmetic operators, conversion operators, comparison operators
     * 
     * Valid grade range: 0-100
     */
    class Grade {
    private:
        double score;  // The numeric score (0-100)
        
        // Static members
        static double passingGrade;  // Minimum passing grade (default 60)
        static int totalGradesCreated;

        /**
         * @brief Ensure score is within valid range [0, 100]
         */
        void clamp();

    public:
        // ============ Constructors & Destructor ============
        
        /**
         * @brief Default constructor - creates grade of 0
         */
        Grade();

        /**
         * @brief Parameterized constructor
         * @param score The numeric score
         */
        Grade(double score);

        /**
         * @brief Copy constructor
         * @param other Grade to copy from
         */
        Grade(const Grade& other);

        /**
         * @brief Destructor
         */
        ~Grade();

        // ============ Getters & Setters ============

        /**
         * @brief Get numeric score - const method
         * @return The score
         */
        inline double getScore() const {
            return score;
        }

        /**
         * @brief Set score
         * @param newScore New score value
         */
        void setScore(double newScore);

        /**
         * @brief Check if passing - const method
         * @return true if score >= passingGrade
         */
        bool isPassing() const;

        /**
         * @brief Get letter grade - const method
         * @return Letter grade (A, B, C, D, F)
         */
        std::string getLetterGrade() const;

        // ============ Static methods ============

        static void setPassingGrade(double grade);
        static double getPassingGrade();
        static int getTotalGradesCreated();

        // ============ ARITHMETIC OPERATORS ============

        /**
         * @brief Add two grades
         * @param other Grade to add
         * @return New grade with sum of scores (clamped to 100)
         */
        Grade operator+(const Grade& other) const;

        /**
         * @brief Add a number to grade
         * @param value Value to add
         * @return New grade with increased score
         */
        Grade operator+(double value) const;

        /**
         * @brief Subtract two grades
         * @param other Grade to subtract
         * @return New grade with difference of scores (clamped to 0)
         */
        Grade operator-(const Grade& other) const;

        /**
         * @brief Subtract a number from grade
         * @param value Value to subtract
         * @return New grade with decreased score
         */
        Grade operator-(double value) const;

        /**
         * @brief Multiply grade by a factor
         * @param factor Multiplication factor
         * @return New grade with scaled score
         */
        Grade operator*(double factor) const;

        /**
         * @brief Divide grade by a factor
         * @param factor Division factor
         * @return New grade with scaled score
         */
        Grade operator/(double factor) const;

        /**
         * @brief Add and assign
         * @param other Grade to add
         * @return Reference to this grade
         */
        Grade& operator+=(const Grade& other);

        /**
         * @brief Add number and assign
         * @param value Value to add
         * @return Reference to this grade
         */
        Grade& operator+=(double value);

        /**
         * @brief Subtract and assign
         * @param value Value to subtract
         * @return Reference to this grade
         */
        Grade& operator-=(double value);

        /**
         * @brief Multiply and assign
         * @param factor Multiplication factor
         * @return Reference to this grade
         */
        Grade& operator*=(double factor);

        // ============ INCREMENT/DECREMENT OPERATORS (Prefix & Postfix) ============

        /**
         * @brief Prefix increment (++grade)
         * Increases score by 1
         * @return Reference to this grade
         */
        Grade& operator++();

        /**
         * @brief Postfix increment (grade++)
         * Increases score by 1, returns old value
         * @param dummy Dummy parameter to distinguish from prefix
         * @return Copy of grade before increment
         */
        Grade operator++(int dummy);

        /**
         * @brief Prefix decrement (--grade)
         * Decreases score by 1
         * @return Reference to this grade
         */
        Grade& operator--();

        /**
         * @brief Postfix decrement (grade--)
         * Decreases score by 1, returns old value
         * @param dummy Dummy parameter to distinguish from prefix
         * @return Copy of grade before decrement
         */
        Grade operator--(int dummy);

        // ============ COMPARISON OPERATORS ============

        /**
         * @brief Equality comparison
         * @param other Grade to compare with
         * @return true if scores are equal
         */
        bool operator==(const Grade& other) const;

        /**
         * @brief Inequality comparison
         * @param other Grade to compare with
         * @return true if scores are not equal
         */
        bool operator!=(const Grade& other) const;

        /**
         * @brief Less than comparison
         * @param other Grade to compare with
         * @return true if this score < other score
         */
        bool operator<(const Grade& other) const;

        /**
         * @brief Greater than comparison
         * @param other Grade to compare with
         * @return true if this score > other score
         */
        bool operator>(const Grade& other) const;

        /**
         * @brief Less than or equal comparison
         * @param other Grade to compare with
         * @return true if this score <= other score
         */
        bool operator<=(const Grade& other) const;

        /**
         * @brief Greater than or equal comparison
         * @param other Grade to compare with
         * @return true if this score >= other score
         */
        bool operator>=(const Grade& other) const;

        // ============ CONVERSION OPERATORS ============

        /**
         * @brief Convert grade to int
         * @return Score as integer
         */
        operator int() const;

        /**
         * @brief Convert grade to double
         * @return Score as double
         */
        operator double() const;

        /**
         * @brief Convert grade to string (letter grade)
         * @return Letter grade string
         */
        operator std::string() const;

        // ============ STREAM OPERATORS (Friend) ============

        /**
         * @brief Output stream operator
         * @param os Output stream
         * @param grade Grade to output
         * @return Reference to output stream
         */
        friend std::ostream& operator<<(std::ostream& os, const Grade& grade);

        /**
         * @brief Input stream operator
         * @param is Input stream
         * @param grade Grade to input into
         * @return Reference to input stream
         */
        friend std::istream& operator>>(std::istream& is, Grade& grade);

        // ============ NON-MEMBER ARITHMETIC OPERATORS ============

        /**
         * @brief Add number to grade (reverse order)
         * @param value Number to add
         * @param grade Grade to add to
         * @return New grade with sum
         */
        friend Grade operator+(double value, const Grade& grade);

        /**
         * @brief Multiply grade by factor (reverse order)
         * @param factor Multiplication factor
         * @param grade Grade to multiply
         * @return New grade with product
         */
        friend Grade operator*(double factor, const Grade& grade);
    };

} // namespace grading

#endif // GRADE_HPP