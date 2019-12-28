// CopyRight (c) by shao qiang xu. data 27.12.2019. All rights reserved. email: shao_qiang_xu@foxmail.com
// implement test functions in chapter 1
#include "include/chapter1.h"

#include <map>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>

// one line in the file should be like this:
// 2 abs ded dfaef fdfd wedq dqwd ...
// 1 asf ded dfasdef fdfd ds dqwd ...
// 3 abs das dfaesdf fdfd ds f ...
static void ReadData(const std::string &file_path,
		std::vector< std::pair<std::string, int> > *term_documentsid) {
	std::ifstream data_file_head(file_path);
	if (!data_file_head.is_open()) {
		std::cerr << file_path << " not exists! return" << std::endl;
		return;
	} // end if
    std::string line;
	while (getline(data_file_head, line)) {
        std::cout << line << std::endl;
		std::istringstream line_stream(line);
		int doc_id = 0;
		line_stream >> doc_id;
		std::string term;
		while (line_stream >> term) {
			term_documentsid->push_back({ term, doc_id });
		} // end while
	} // end while
} // end ReadData

static void Sort(std::vector< std::pair<std::string, int> > *term_documentsid) {
	std::sort(term_documentsid->begin(), term_documentsid->end(),
		[](const auto &p1, const auto &p2) {
		return p1.first < p2.first ||
			p1.first == p2.first && p1.second < p2.second;
		});
} // end Sort

static void GenerateInvertedIndexes(const std::vector< std::pair<std::string, int> > &term_documentsid,
		std::map< std::string, std::pair<int, std::vector<int> > > *inverted_indexes) {
	int left = 0;
	while (left < term_documentsid.size()) {
		int right = left;
		std::vector<int> doc_ids;
		while (right < term_documentsid.size() &&
			term_documentsid[left].first == term_documentsid[right].first) {
			doc_ids.push_back(term_documentsid[right].second);
            ++right;
		} // end while
		inverted_indexes->insert({ term_documentsid[left].first, {right - left, doc_ids }});
		left = right;
	} // end while
} // end GenerateInvertedIndexes

static void PrintInvertedIndexes(const std::map< std::string, std::pair<int, std::vector<int> > > &inverted_indexes) {
	for (const auto &p : inverted_indexes) {
		std::cout << "( " << p.first << ", " << p.second.first << " ): ";
		for (auto i : p.second.second) std::cout << i << " ";
		std::cout << std::endl;
	} // end for
} // end PrintInvertedIndexes

static void QueryAnd(const std::map< std::string, std::pair<int, std::vector<int> > > &inverted_indexes,
        const std::vector<std::string> &keys, std::set<int> *query_result) {
    std::map<int, int> counter;
    for (const auto &s : keys) {
        if (inverted_indexes.find(s) != inverted_indexes.end()) {
            for (auto i : inverted_indexes.at(s).second)
                ++counter[i];
        } // end if
    } // end for
    for (const auto &p : counter) {
        if (p.second == keys.size())
            query_result->insert(p.first);
    } // end for
} // end QueryAnd

static void QueryOr(const std::map< std::string, std::pair<int, std::vector<int> > > &inverted_indexes,
        const std::vector<std::string> &keys, std::set<int> *query_result) {
    for (const auto &s : keys) {
        if (inverted_indexes.find(s) != inverted_indexes.end()) {
            for (auto i : inverted_indexes.at(s).second)
                query_result->insert(i);
        } // end if
    } // end for
} // end QueryOr

static void And(const std::set<int> &query_result1, const std::set<int> &query_result2, std::set<int> *result_and) {
    std::set_intersection(query_result1.begin(), query_result1.end(), query_result2.begin(), query_result2.end(),
            std::inserter(*result_and, result_and->end()));
} // end And

static void Or(const std::set<int> &query_result1, const std::set<int> &query_result2, std::set<int> *result_or) {
    std::set_union(query_result1.begin(), query_result1.end(), query_result2.begin(), query_result2.end(),
            std::inserter(*result_or, result_or->end()));
} // end Or

static void Diff(const std::set<int> &query_result1, const std::set<int> &query_result2, std::set<int> *result_diff) {
    std::set_difference(query_result1.begin(), query_result1.end(), query_result2.begin(), query_result2.end(),
            std::inserter(*result_diff, result_diff->end()));
} // end Diff

static void GetAllIndexes(const std::map< std::string, std::pair<int, std::vector<int>> > &inverted_indexes, std::set<int> *all_indexes) {
    for (const auto &p : inverted_indexes) {
        all_indexes->insert(p.second.second.begin(), p.second.second.end());
    } // end for
} // end GetAllIndexes

static void NotInvertedIndexes(const std::map< std::string, std::pair<int, std::vector<int> > > &inverted_indexes, const std::set<int> &query_result,
        std::set<int> *result_not) {
    std::set<int> all_indexes;
    GetAllIndexes(inverted_indexes, &all_indexes);
    Diff(all_indexes, query_result, result_not);
} // end NotInvertedIndexes

static void NotAllIndexes(const std::set<int> &all_indexes, const std::set<int> &query_result, std::set<int> *result_not) {
    Diff(all_indexes, query_result, result_not);
} // end NotAllIndexes

static void AndNot(const std::set<int> &query_result1, const std::set<int> &query_result2, std::set<int> *result_and_not) {
    auto it1 = query_result1.begin(), it2 = query_result2.begin();
    while (it1 != query_result1.end() && it2 != query_result2.end()) {
        if (*it1 == *it2) {
            ++it1;
            ++it2;
        } else if (*it1 > *it2) {
            ++it2;
        } else {
            result_and_not->insert(*it1++);
        } // end else
    } // end while
} // end AndNot

void TestC1E1() {
	std::string file_path = "./../data/1.1.txt";
	std::vector< std::pair<std::string, int> > term_documentsid;
	std::map< std::string, std::pair<int, std::vector<int> > > inverted_indexes;
	ReadData(file_path, &term_documentsid);
	Sort(&term_documentsid);
	GenerateInvertedIndexes(term_documentsid, &inverted_indexes);
	PrintInvertedIndexes(inverted_indexes);
} // end TestC1E1

void TestC1E2() {
    std::string file_path = "./../data/1.2.txt";
	std::vector< std::pair<std::string, int> > term_documentsid;
	std::map< std::string, std::pair<int, std::vector<int> > > inverted_indexes;
	ReadData(file_path, &term_documentsid);
	Sort(&term_documentsid);
	GenerateInvertedIndexes(term_documentsid, &inverted_indexes);
	PrintInvertedIndexes(inverted_indexes);
} // end TestC1E2

void TestC1E3() {
    std::string file_path = "./../data/1.2.txt";
	std::vector< std::pair<std::string, int> > term_documentsid;
	std::map< std::string, std::pair<int, std::vector<int> > > inverted_indexes;
	ReadData(file_path, &term_documentsid);
	Sort(&term_documentsid);
	GenerateInvertedIndexes(term_documentsid, &inverted_indexes);
    std::cout << "Query \"schizophrenia AND drug\": " << std::endl;
    std::vector<std::string> keys{"schizophrenia", "drug"};
    std::set<int> query_result;
    QueryAnd(inverted_indexes, keys, &query_result);
    for (auto i : query_result) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Query \"for AND NOT (drug OR approach)\": " << std::endl;
    std::vector<std::string> keys1{"for"}, keys2{"drug", "approach"};
    std::set<int> query_result1, query_result2, query_result_not;
    QueryAnd(inverted_indexes, keys1, &query_result1);
    QueryOr(inverted_indexes, keys2, &query_result2);
    NotInvertedIndexes(inverted_indexes, query_result2, &query_result_not);
    query_result.clear();
    And(query_result1, query_result_not, &query_result);
    for (auto i : query_result) std::cout << i << " ";
    std::cout << std::endl;
} // end TestC1E3
