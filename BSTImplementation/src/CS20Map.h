/*
 * CS20Map.h
 *
 *  Created on: Nov 17, 2016
 *      Author: rogel
 */

#ifndef CS20MAP_H_
#define CS20MAP_H_

#include "BST.h"

template<typename T1, typename T2>
struct MapEntry {
	T1 entryKey;
	T2 entryValue;
	bool operator<(const MapEntry& rightSide) {
		return (this->entryKey < rightSide.entryKey);
	}
	bool operator>(const MapEntry& rightSide) {
		return (this->entryKey > rightSide.entryKey);
	}
	bool operator==(const MapEntry& rightSide) {
		return (this->entryKey == rightSide.entryKey);
	}
};

template<typename T1, typename T2>
class CS20Map {
private:
	BST<MapEntry<T1, T2> > theTree;
public:
	void Insert(T1 key, T2 value) {
		/// 1) Create a MapEntry object
		/// 2) Use the BST insert method
		MapEntry<T1, T2> newMap(key, value);
		theTree.Insert(newMap);
	}
	bool Find(T1 key) {
		/// 1) Create a MapEntry object
		/// 2) Use the BST find method
		MapEntry<T1, T2> newMap(key);
		if (theTree.Find(newMap) == NULL) {
			return false;
		}
		return true;
	}
	T2 Get(T1 key) {
		/// 1) Create a MapEntry object
		/// 2) Use the BST find method
		/// 3) Return the entryValue component from
		///     the inside the resulting node
		MapEntry<T1, T2> newMap(key);
		BSTNode<MapEntry<T1, T2> > * result = theTree.Find(newMap);
		return result->key.entryValue;
	}
};

#endif /* CS20MAP_H_ */
