#pragma once

namespace MonteCarlo {
	template <class T>
	class Clonable
	{
	public:
		Clonable()
		{
			DataPtr = nullptr;
		}

		Clonable(const T& inner)
		{
			DataPtr = inner.clone();
		}

		~Clonable()
		{
			if (DataPtr != nullptr)
			{
				delete DataPtr;
			}
		}

		Clonable(const Clonable<T>& original)
		{
			if (original.DataPtr != nullptr)
			{
				DataPtr = original.DataPtr->clone();
			}
			else
			{
				DataPtr = nullptr;
			}
		}

		Clonable& operator=(const Clonable<T>& original)
		{
			if (this != &original)
			{
				if (DataPtr != nullptr)
				{
					delete DataPtr;
				}

				DataPtr = original.DataPtr != nullptr ?
					original.DataPtr->clone() : nullptr;
			}

			return *this;
		}

		T& operator*()
		{
			return *DataPtr;
		}

		const T& operator*() const
		{
			return *DataPtr;
		}

		T* operator->()
		{
			return DataPtr;
		}

		const T* const operator->() const
		{
			return DataPtr;
		}

	private:
		T* DataPtr;
	};
}
