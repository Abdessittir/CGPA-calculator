#ifndef STUDENT_H
#define STUDENT_H

#include <string_view>
#include <string>
#include <vector>

struct Course {
  std::string name{};
  char grade{};
};

class Student {
private:
  int m_id{};
  std::string m_full_name{};
  std::string m_password{};
  float m_grade_point{};
  char m_grade_letter{};
  using Courses = std::vector<Course*>;
  Courses m_courses{};
public:
  Student(int id, std::string_view full_name, std::string_view password)
    :m_id{id}, m_full_name{full_name}, m_password{password}{}
  
  void add_course(Course& course) {
    m_courses.push_back(&course);
  }

  void remove_course(std::string_view course_name) {
    std::erase_if(m_courses, [course_name](Course* course) { return course_name == course->name; });
  };

  const Courses get_student_course() const {
    return m_courses;
  }
};

#endif