/*
 * CPoiDatabase.h
 *
 *  Created on: 26.12.2017
 *      Author: Fabian Alexander Wilms
 */

#ifndef CDATABASE_H_
#define CDATABASE_H_

#include <iostream>
#include <map>
#include <string>

/**
 * A class to store POIs
 */
template<typename K, typename T>
class CDatabase {
public:
	/**
	 * Constructor creates a new database
	 */
	CDatabase();

	/**
	 * Destructor
	 */
	virtual ~CDatabase();

	/**
	 * Add an element to the database
	 */
	void addElement(T const& object);

	/**
	 * Search the PoiDatabase for a element by its name and returns a pointer to it
	 *
	 * @param name 	The name of the element to be searched
	 *
	 * @return A pointer to the element with the given name
	 */
	T* getPointerToElement(K key);

	/**
	 * Returns a const reference to the std::map used to store the database
	 *
	 * @return A const reference to the std::map
	 */
	const std::map<K, T>& getDB() const;

	/**
	 * Deletes all elements of the database
	 */
	void clearDb();
private:
	/**
	 * A map to store all known elements
	 */
	std::map<K, T> m_storage;
};

template<typename K, typename T>
inline CDatabase<K, T>::CDatabase() {
}

template<typename K, typename T>
inline void CDatabase<K, T>::addElement(const T& object) {
	m_storage.insert(std::pair<K,T>(object.getName(), object));
}

template<typename K, typename T>
inline T* CDatabase<K, T>::getPointerToElement(K key) {
	T* returnValue = nullptr;

	typename std::map<K, T>::iterator it = m_storage.find(key);

	if(it == m_storage.end()) {
		// nothing found
#ifdef DEBUG
		std::cout << "INFO in CDatabase::getPointerToElement(): Could not find element '" << key << "'" << std::endl;
#endif
		returnValue = nullptr;
	} else {
		returnValue = &(it->second);

	}

	return returnValue;
}

template<typename K, typename T>
inline const std::map<K, T>& CDatabase<K, T>::getDB() const {
	return m_storage;
}

template<typename K, typename T>
inline CDatabase<K, T>::~CDatabase() {
}

template<typename K, typename T>
inline void CDatabase<K, T>::clearDb() {
	m_storage.clear();
}

#endif /* CDATABASE_H_ */
