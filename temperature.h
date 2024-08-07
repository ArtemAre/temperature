#pragma once
#include <cstdlib>
using uint64_t = unsigned long long;

namespace temperature {

	constexpr bool diff(long double x, long double y, long double res = 0.0001) {
		return abs(x - y) <= res;
	}

	class Celcium
	{
		long double value;
	public:
		Celcium(long double elem) :value{ elem } {}
		Celcium(const Celcium& elem) = default;
		Celcium& operator=(const Celcium& elem) = default;

		const long double get()const noexcept { return value; }
		[[noreturn]] void set(long double new_value)noexcept { value = new_value; }

		friend bool operator==(const Celcium& celc, const Celcium& celc2) { return diff(celc.value, celc2.value); }
		friend bool operator!=(const Celcium& celc, const Celcium& celc2) { return !(celc == celc2); }
		friend bool operator>(const Celcium& celc, const Celcium& celc2) { return celc.get() > celc.get(); }
		friend bool operator<(const Celcium& celc, const Celcium& celc2) { return celc.get() < celc.get(); }
		friend bool operator>=(const Celcium& celc, const Celcium& celc2) { return celc.get() >= celc.get(); }
		friend bool operator<=(const Celcium& celc, const Celcium& celc2) { return celc.get() <= celc.get(); }
		explicit operator long double() { return value; }
	};

	class Fharengeit
	{
		long double value;
	public:
		Fharengeit(long double elem) :value{ elem } {}
		Fharengeit(const Fharengeit& far) = default;
		Fharengeit& operator=(const Fharengeit& far) = default;

		const long double get()const noexcept { return value; }
		[[noreturn]] void set(long double new_value)noexcept { value = new_value; }

		friend bool operator==(const Fharengeit& far, const Fharengeit& far2) { return diff(far.value, far2.value); }
		friend bool operator!=(const Fharengeit& far, const Fharengeit& far2) { return !(far == far2); }
		friend bool operator>(const Fharengeit& celc, const Fharengeit& celc2) { return celc.get() > celc.get(); }
		friend bool operator<(const Fharengeit& celc, const Fharengeit& celc2) { return celc.get() < celc.get(); }
		friend bool operator>=(const Fharengeit& celc, const Fharengeit& celc2) { return celc.get() >= celc.get(); }
		friend bool operator<=(const Fharengeit& celc, const Fharengeit& celc2) { return celc.get() <= celc.get(); }

		explicit operator long double() { return value; }
	};
	class Kelvin
	{
		uint64_t value;
	public:
		Kelvin(uint64_t elem) :value{ elem } {}
		Kelvin(const Kelvin& elem) = default;
		Kelvin& operator=(const Kelvin& elem) = default;

		const float get()const noexcept { return value; }
		[[noreturn]] void set(uint64_t new_value)noexcept { value = new_value; }

		friend bool operator==(const Kelvin& celc, const Kelvin& celc2) { return celc.value == celc2.value; }
		friend bool operator!=(const Kelvin& celc, const Kelvin& celc2) { return !(celc == celc2); }
		friend bool operator>(const Kelvin& celc, const Kelvin& celc2) { return celc.get() > celc.get(); }
		friend bool operator<(const Kelvin& celc, const Kelvin& celc2) { return celc.get() < celc.get(); }
		friend bool operator>=(const Kelvin& celc, const Kelvin& celc2) { return celc.get() >= celc.get(); }
		friend bool operator<=(const Kelvin& celc, const Kelvin& celc2) { return celc.get() <= celc.get(); }

		explicit operator unsigned long long() { return value; }

	};

	Celcium operator""_C(long double dob) {
		return Celcium{ dob };
	}

	Kelvin operator""_K(unsigned long long f) {
		return Kelvin{ f };
	}

	Fharengeit operator""_F(long double f) {
		return Fharengeit{ f };
	}

	template<class T, class M>
	class convert {};

	template<>
	class convert<Celcium, Kelvin> {
	public:
		//from Celcium in Kelvin
		Kelvin convert_to(const Celcium& celc) {
			return Kelvin{ static_cast<uint64_t>(celc.get()) + 273 };
		}
	};

	template<>
	class convert<Kelvin, Celcium> {
	public:
		//from Kelvin in Celcium
		Celcium convert_to(const Kelvin& celc) {
			return Celcium{ static_cast<long double>(celc.get()) - 273 };
		}
	};

	template<>
	class convert<Celcium, Fharengeit> {
	public:
		//from Celcium in Fharengeit
	public:
		Fharengeit convert_to(const Celcium& celc) {
			return Fharengeit{ celc.get() / (5 / 9) + 32 };
		}
	};

	template<>
	class convert<Fharengeit, Celcium> {
		//from Fharengeit in celcium
	public:
		Celcium convert_to(const Fharengeit& celc) {
			return Celcium{ (celc.get() - 32) * (5 / 9) };
		}
	};

	template<>
	class convert<Kelvin, Fharengeit> {
		//from kelvin in Fharengeit
	public:
		Fharengeit convert_to(const Kelvin& celc) {
			return Fharengeit{ (celc.get() - 273) / (5 / 9) + 32 };
		}
	};

	template<>
	class convert<Fharengeit, Kelvin> {
		//from Fharengeit in Kelvin
	public:
		Kelvin convert_to(const Fharengeit& celc) {
			return Kelvin{ 273 + (static_cast<uint64_t>(celc.get()) - 32) * (5 / 9) };
		}
	};

	template<class C, class S>
	C convert_to(const S& c) {
		convert<S, C> conv{};
		return conv.convert_to(c);
	}

}
