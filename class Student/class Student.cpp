#include <iostream>
#include<ctime>
using namespace std;

class Date {
	unsigned short day : 5;
	unsigned short month : 4;
	short year;
public:
	void SetDates(unsigned short day, unsigned short month, short year)
	{
		SetDay(day);
		SetMonth(month);
		SetYear(year);
	}

	void SetDay(unsigned short day)
	{
		if (month % 2 == 0 && month != 2)
		{
			if (day > 30 && day == 0)
				throw "Error";

		}
		else if (month % 2 != 0 && month != 2)
		{
			if (day > 31 && day == 0)
				throw "Error";

		}
		else
		{
			if (day > 28 && day == 0)
				throw "Error";

		}
		this->day = day;
		if (month > 12 && month == 0)
			throw "Error";
		this->month = month;
		this->year = year;
	}
	void SetMonth(unsigned short month)
	{
		if (month > 12 && month == 0)
			throw "Error";
		this->month = month;
	}
	void SetYear(short year)
	{
		this->year = year;
	}
	unsigned short GetDay()
	{
		return day;
	}
	unsigned short GetMonth()
	{
		return month;
	}
	short GetYear()
	{
		return year;
	}
};
class Student {
	string name;
	string second_name;
	string surname;
	string number;
	string home_email;
	Date birthday;
	Date study_date;
	short homeworks_count = 5;
	short classworks_count = 5;
	short exams_count = 5;
	double* homework_rates = new double[homeworks_count];
	double* classwork_rates = new double[classworks_count];
	double* exam_rates = new double[exams_count];
public:	
	~Student() {
		if (homework_rates != nullptr)
			delete[] homework_rates;
		if (classwork_rates != nullptr)
			delete[] classwork_rates;
		if (exam_rates != nullptr)
			delete[] exam_rates;
	}
	Student() : Student("Oleg", "Markov", "0654968793") {}
	Student(string name, string surname, string number)
	{
		this->name = name;
		second_name = "Olegovich";
		this->surname = surname;
		this->number = number;
		home_email = "fghfgfg@gmail.com";
		birthday.SetDay(1 + rand() % (32 - 1));
		birthday.SetMonth(1 + rand() % (13 - 1));
		birthday.SetYear(-2000 + rand() % (5000 - 2000));
		birthday.SetDates(birthday.GetDay(), birthday.GetMonth(), birthday.GetYear());

		study_date.SetDay(1 + rand() % (32 - 1));
		study_date.SetMonth(1 + rand() % (13 - 1));
		study_date.SetYear(-2000 + rand() % (5000 - 2000));
		study_date.SetDates(study_date.GetDay(), study_date.GetMonth(), study_date.GetYear());
		SetClassWorkRates(classwork_rates);
		SetExamRates(exam_rates);
		SetHomeWorkRates(homework_rates);
	}

	void AddExamRate(double exam_rate)
	{
		if (exam_rate > 0 && exam_rate < 13)
		{
			double* temp = new double[exams_count + 1];
			for (int i = 0; i < exams_count + 1; i++)
			{
				temp[i] = exam_rates[i];
			}
			temp[exams_count] = exam_rate;
			exams_count++;
			delete[] exam_rates;
			exam_rates = temp;
		}
		else
			throw"Error";
	}
	void AddClassWorkRate(double classwork_rate)
	{
		if (classwork_rate > 0 && classwork_rate < 13)
		{
			double* temp = new double[classworks_count + 1];
			for (int i = 0; i < classworks_count + 1; i++)
			{
				temp[i] = classwork_rates[i];
			}
			temp[classworks_count] = classwork_rate;
			classworks_count++;
			delete[] classwork_rates;
			classwork_rates = temp;
		}
		else
			throw"Error";
	}
	void AddHomeWorkRate(double homework_rate)
	{
		if(homework_rate > 0 && homework_rate < 13)
		{
			double* temp = new double[homeworks_count + 1];
			for (int i = 0; i < homeworks_count + 1; i++)
			{
				temp[i] = homework_rates[i];
			}
			temp[homeworks_count] = homework_rate;
			homeworks_count++;
			delete[] homework_rates;
			homework_rates = temp;
		}
		else
			throw"Error";
	}
	void DeleteExamRate(double exam_rate)
	{
		if (exam_rate > 0 && exam_rate < 13)
		{
			for (int i = 0; i < exams_count; i++)
			{
				if (exam_rate == exam_rates[i])
				{
					double* temp = new double[exams_count - 1];
					for (int i = 0; i < exams_count; i++)
					{
						if (exam_rate == exam_rates[i])
						{
							temp[i] = exam_rates[i + 1];
							i++;
						}
						else
							temp[i] = exam_rates[i];
					}
					delete[] exam_rates;
					exams_count--;
					exam_rates = temp;
				}
			}
		}
		else
			throw"Error";
	}
	void DeleteHomeWorkRate(double homework_rate)
	{
		if (homework_rate > 0 && homework_rate < 13)
		{
		for (int i = 0; i < homeworks_count; i++)
		{
			if (homework_rate == homework_rates[i])
			{
				double* temp = new double[homeworks_count - 1];
				for (int i = 0; i < homeworks_count; i++)
				{
					if (homework_rate == homework_rates[i])
					{
						temp[i] = homework_rates[i + 1];
						i++;
					}
					else
						temp[i] = homework_rates[i];
				}
				delete[] homework_rates;
				homeworks_count--;
				homework_rates = temp;
				}
			}
		}
		else
			throw"Error";
	}
	void DeleteClassWorkRate(double classwork_rate)
	{
		if (classwork_rate > 0 && classwork_rate < 13)
		{
			for (int i = 0; i < classworks_count; i++)
			{
				if (classwork_rate == classwork_rates[i])
				{
					double* temp = new double[classworks_count - 1];
					for (int i = 0; i < classworks_count; i++)
					{
						if (classwork_rate == classwork_rates[i])
						{
							temp[i] = classwork_rates[i + 1];
							i++;
						}
						else
							temp[i] = classwork_rates[i];
					}
					delete[] classwork_rates;
					classworks_count--;
					classwork_rates = temp;
				}
			}
		}
		else
			throw"Error";
	}
	void DeleteHomeWorkRateIndex(int homework_rate_index)
	{
		if (homework_rate_index >= 0 && homeworks_count > homework_rate_index)
		{

			bool ok = false;
			for (int i = 0; i < homeworks_count; i++)
			{
				if (homework_rate_index == i)
				{
					double* temp = new double[homeworks_count - 1];
					for (int i = 0; i < homeworks_count - 1; i++)
					{
						if (homework_rate_index == i)
						{
							temp[i] = homework_rates[i + 1];
							ok = true;
						}
						else if (!ok)
							temp[i] = homework_rates[i];
						else
						{
							temp[i] = homework_rates[i + 1];

						}

					}
					delete[] homework_rates;
					homeworks_count--;
					homework_rates = temp;
				}
			}
		}
		else
			throw"Error";
	}
	void DeleteExamRateIndex(int exam_rate_index)
	{
		if (exam_rate_index >= 0 && exams_count > exam_rate_index)
		{

			bool ok = false;
			for (int i = 0; i < exams_count; i++)
			{
				if (exam_rate_index == i)
				{
					double* temp = new double[exams_count - 1];
					for (int i = 0; i < exams_count - 1; i++)
					{
						if (exam_rate_index == i)
						{
							temp[i] = exam_rates[i + 1];
							ok = true;
						}
						else if (!ok)
							temp[i] = exam_rates[i];
						else
						{
							temp[i] = exam_rates[i + 1];

						}

					}
					delete[] exam_rates;
					exams_count--;
					exam_rates = temp;
				}
			}
		}
		else
			throw"Error";
	}
	void DeleteClassWorkRateIndex(int classwork_rate_index)
	{
		if (classwork_rate_index >= 0 && classworks_count > classwork_rate_index)
		{

			bool ok = false;
			for (int i = 0; i < classworks_count; i++)
			{
				if (classwork_rate_index == i)
				{
					double* temp = new double[classworks_count - 1];
					for (int i = 0; i < classworks_count - 1; i++)
					{
						if (classwork_rate_index == i)
						{
							temp[i] = classwork_rates[i + 1];
							ok = true;
						}
						else if (!ok)
							temp[i] = classwork_rates[i];
						else
						{
							temp[i] = classwork_rates[i + 1];

						}

					}
					delete[] classwork_rates;
					classworks_count--;
					classwork_rates = temp;
				}
			}
		}
		else
			throw"Error";
	}
	void SetClassWorkRates(double* classwork_rates)
	{
		for (int i = 0; i < classworks_count; i++)
		{
			classwork_rates[i] = rand() % 121 / 10.0;
		}
	}
	double* GetClassWorkRates()
	{
		return classwork_rates;
	}
	void SetHomeWorkRates(double* homework_rates)
	{
		for (int i = 0; i < homeworks_count; i++)
		{
			homework_rates[i] = rand() % 121 / 10.0;
		}
	}
	double* GetHomeWorkRates()
	{
		return homework_rates;
	}
	void SetExamRates(double* exam_rates)
	{
		for (int i = 0; i < exams_count; i++)
		{
			exam_rates[i] = rand() % 121 / 10.0;
		}
	}
	double* GetExamRates()
	{
		return exam_rates;
	}
	void SetBirthday(Date& birthday, unsigned short day, unsigned short month, short year)
	{
		birthday.SetDates(day, month, year);
	}
	Date GetBirthday()
	{
		return birthday;
	}
	void SetStudyDate(Date& study_date, unsigned short day, unsigned short month, short year)
	{
		study_date.SetDates(day, month, year);
	}
	void SetHomeEmail(string home_email)
	{
		this->home_email = home_email;
	}
	string GetHomeEmail()
	{
		return home_email;
	}
	void SetNumber(string number)
	{
		this->number = number;
	}
	string GetNumber()
	{
		return number;
	}
	void SetName(string name)
	{
		this->name = name;
	}
	string GetName()
	{
		return name;
	}
	void SetSecondName(string second_name)
	{
		this->second_name = second_name;
	}
	string GetSecondName()
	{
		return second_name;
	}
	void SetSurName(string surname)
	{
		this->surname = surname;
	}
	string GetSurName()
	{
		return surname;
	}
	void ViewAllHomeworkRates()
	{
		for (int i = 0; i < homeworks_count; i++)
		{
			cout << homework_rates[i] << " ";
		}
		cout << "\n";
	}
	void ViewAllClassworkRates()
	{
		for (int i = 0; i < classworks_count; i++)
		{
			cout << classwork_rates[i] << " ";
		}
		cout << "\n";
	}
	void ViewAllExamRates()
	{
		for (int i = 0; i < exams_count; i++)
		{
			cout << exam_rates[i] << " ";
		}
		cout << "\n";
	}
	void ViewHomeworkRate(short rate)
	{
		for (int i = 0; i < homeworks_count; i++)
		{
			if(rate < homework_rates[i])
				cout << homework_rates[i] << " ";
		}
		cout << "\n";
	}
	void ViewClassworkRate(short rate)
	{
		for (int i = 0; i < classworks_count; i++)
		{
			if (rate < classwork_rates[i])
				cout << classwork_rates[i] << " ";
		}
		cout << "\n";
	}
	void ViewExamRate(short rate)
	{
		for (int i = 0; i < exams_count; i++)
		{
			if (rate < exam_rates[i])
				cout << exam_rates[i] << " ";
		}
		cout << "\n";
	}
	double GetHomeworkRate(short index_rate)
	{
		for (int i = 0; i < homeworks_count; i++)
		{
			if (index_rate == i)
				return homework_rates[i];
		}
		cout << "\n";
	}
	double GetClassworkRate(short index_rate)
	{
		for (int i = 0; i < classworks_count; i++)
		{
			if (index_rate == i)
				return classwork_rates[i];
		}
		cout << "\n";
	}
	double GetExamRate(short index_rate)
	{
		for (int i = 0; i < exams_count; i++)
		{
			if (index_rate == i)
				return exam_rates[i];
		}
		cout << "\n";
	}
	void Print()
	{
		cout << "FIO:" << name << " " << second_name << " " << surname << "\n";
		cout << "Number:" << number << "\n";
		cout << "Birthday date:" << birthday.GetDay() << "/" << birthday.GetMonth() << "/" << birthday.GetYear() << "\n";
		cout << "Email:" << home_email << "\n";
		cout << "Study start:" << study_date.GetDay() << "/" << study_date.GetMonth() << "/" << study_date.GetYear() << "\n";
		cout << "Homeworks rates: ";
		for (int i = 0; i < homeworks_count; i++)
		{
			cout << homework_rates[i] << ' ';
		}
		cout << "\n";
		cout << "Class works rates: ";
		for (int i = 0; i < classworks_count; i++)
		{
			cout << classwork_rates[i] << ' ';
		}
		cout << "\n";
		cout << "Exams rates: ";
		for (int i = 0; i < exams_count; i++)
		{
			cout << exam_rates[i] << ' ';
		}
		cout << "\n";
	}
};

int main()
{
	srand(time(0));
	Student s("Vasya", "Pupkin", "053 466 8453");
	Date d;
	s.Print();
	//cout << s.GetHomeWorkRates();
	s.AddHomeWorkRate(11.5);
	s.AddClassWorkRate(12);
	s.Print();
	s.DeleteHomeWorkRateIndex(2);
	s.DeleteClassWorkRate(12);
	s.Print();
	cout << s.GetHomeworkRate(3);
	cout << s.GetClassworkRate(4);
	cout << s.GetExamRate(3);
	s.DeleteExamRateIndex(3);
	s.Print();
	s.AddExamRate(12);
	s.AddHomeWorkRate(12);
	s.Print();
	

}
