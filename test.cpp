#include <iostream>
#include <map>

using namespace std;

class IFieldOrm { 
 public:
  virtual ~IFieldOrm() {}
  virtual void save() = 0;
  virtual void get() = 0;
  virtual void migrate() = 0;
};

class BaseOrm {
 public:
  virtual ~BaseOrm();

  virtual void save();
  virtual void get();
  virtual void migrate();

 protected:
  map<string, IFieldOrm *> m_fields;
};

void BaseOrm::save() {
  for (auto &f : m_fields)
    f.second->save();
}

void BaseOrm::get() {
  for (auto &f : m_fields)
    f.second->get();
}

void BaseOrm::migrate() {
  for (auto &f : m_fields)
    f.second->migrate();
}

BaseOrm::~BaseOrm() {
  for (auto &f : m_fields)
    delete f.second;
}

class StringFieldOrm : public IFieldOrm {
 public:
  explicit StringFieldOrm(const string &value) : m_value(value) {}

  StringFieldOrm() {}

  void save() override;
  void migrate() override;
  void get() override;

 private:
  string m_value;
};

void StringFieldOrm::save() {
  cout << "Save value " << m_value << endl;
}

void StringFieldOrm::get() {
    cout << "Getting value" << endl;
}

void StringFieldOrm::migrate() {
  cout << "Migrate value " << m_value << endl;
}

class IntFieldOrm : public IFieldOrm {
 public:
  explicit IntFieldOrm(int &value) : m_value(value) {}

  IntFieldOrm() {}

  void save() override;
  void migrate() override;
  void get() override;

 private:
  int m_value;
};

void IntFieldOrm::save() {
  cout << "Save value " << m_value << endl;
}

void IntFieldOrm::get() {
  cout << "Get value " << m_value << endl;
}

void IntFieldOrm::migrate() {
    cout << "Migrate value " << m_value << endl;
}

class UserProfile: public BaseOrm {
 public:
    UserProfile(const string& username, const string& email, int age);

    UserProfile();
};

UserProfile::UserProfile(const string& username, const string& email, int age) {
    m_fields["username"] = new StringFieldOrm(username);
    m_fields["email"] = new StringFieldOrm(email);
    m_fields["age"] = new IntFieldOrm(age);
}

int main() {
    UserProfile user = UserProfile("Batman", "bw@batmail.com", 30);
    user.save();

    return 0;
}
