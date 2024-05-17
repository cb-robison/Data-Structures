#pragma once

class Counter {
private:
	int current_value;
public:
	Counter(int init_value) {
		SetCount(init_value);
	}

	void Reset() {
		current_value = 0;
	}

	void SetCount(int new_value) {
		if (new_value < 0) {
			Reset();
		}
		else {
			current_value = new_value;
		}
	}

	void Increment() {
		current_value++;
	}

	void Decrement() {
		if (current_value < 0)
			Reset();
		else
			current_value--;
	}

	int GetCount() {
		return current_value;
	}

	void operator=(int i) { // Tested
		SetCount(i);
	}

	void operator=(Counter right) { // Tested
		SetCount(right.current_value);
	}

	Counter operator++(int) { // Tested
		Increment();
		Counter new_value(current_value);
		return new_value;
	}
	Counter operator--(int) { // Tested
		Decrement();
		Counter new_value(current_value);
		return new_value;
	}

	bool operator<(int value) { // Tested
		if (current_value < value)
			return true;
		else
			return false;
	}

	bool operator<(Counter rhs) { // Tested
		if (current_value < rhs.GetCount())
			return true;
		else
			return false;
	}

	bool operator>(int value) { // Tested
		if (current_value > value)
			return true;
		else
			return false;
	}

	bool operator>(Counter rhs) { // Tested
		if (current_value > rhs.GetCount())
			return true;
		else
			return false;
	}

	bool operator==(int value) { // Tested
		if (current_value == value)
			return true;
		else
			return false;
	}

	bool operator==(Counter rhs) { // Tested
		if (current_value == rhs.GetCount())
			return true;
		else
			return false;
	}

	bool operator<=(int value) { // Tested
		if (current_value <= value)
			return true;
		else
			return false;
	}

	bool operator<=(Counter rhs) { // Tested
		if (current_value <= rhs.GetCount())
			return true;
		else
			return false;
	}

	bool operator>=(int value) { // Tested
		if (current_value >= value)
			return true;
		else
			return false;
	}

	bool operator>=(Counter rhs) { // Tested
		if (current_value >= rhs.GetCount())
			return true;
		else
			return false;
	}
};
