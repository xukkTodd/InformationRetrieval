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
}

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
}

static void PrintInvertedIndexes(const std::map< std::string, std::pair<int, std::vector<int> > > &inverted_indexes) {
	for (const auto &p : inverted_indexes) {
		std::cout << "( " << p.first << ", " << p.second.first << " ): ";
		for (auto i : p.second.second) std::cout << i << " ";
		std::cout << std::endl;
	} // end for
}

static void Query(const std::map< std::string, std::pair<int, std::vector<int> > > &inverted_indexes,
        const std::vector<std::string> &needs, const std::vector<std::string> &no_needs, std::set<int> *query_result) {
    std::set<int> needs_docs, no_needs_docs;
    for (const auto &s : needs) {
        if (inverted_indexes.find(s) != inverted_indexes.end()) {
            for (auto i : inverted_indexes.at(s).second)
                needs_docs.insert(i);
        } // end if
    } // end for
    for (const auto &s : no_needs) {
        if (inverted_indexes.find(s) != inverted_indexes.end()) {
            for (auto i : inverted_indexes.at(s).second)
                no_needs_docs.insert(i);
        } // end if
    } // end for
    std::set_difference(needs_docs.begin(), needs_docs.end(), no_needs_docs.begin(), no_needs_docs.end(),
            std::inserter(*query_result, query_result->end()));
}

void TestC1E1() {
	std::string file_path = "./../data/1.1.txt";
	std::vector< std::pair<std::string, int> > term_documentsid;
	std::map< std::string, std::pair<int, std::vector<int> > > inverted_indexes;
	ReadData(file_path, &term_documentsid);
	Sort(&term_documentsid);
	GenerateInvertedIndexes(term_documentsid, &inverted_indexes);
	PrintInvertedIndexes(inverted_indexes);
}

void TestC1E2() {
    std::string file_path = "./../data/1.2.txt";
	std::vector< std::pair<std::string, int> > term_documentsid;
	std::map< std::string, std::pair<int, std::vector<int> > > inverted_indexes;
	ReadData(file_path, &term_documentsid);
	Sort(&term_documentsid);
	GenerateInvertedIndexes(term_documentsid, &inverted_indexes);
	PrintInvertedIndexes(inverted_indexes);
}

void TestC1E3() {
    std::string file_path = "./../data/1.2.txt";
	std::vector< std::pair<std::string, int> > term_documentsid;
	std::map< std::string, std::pair<int, std::vector<int> > > inverted_indexes;
	ReadData(file_path, &term_documentsid);
	Sort(&term_documentsid);
	GenerateInvertedIndexes(term_documentsid, &inverted_indexes);
    std::cout << "Query \"schizophrenia OR drug\": " << std::endl;
    std::vector<std::string> needs{"schizophrenia", "drug"}, no_needs;
    std::set<int> query_result;
    Query(inverted_indexes, needs, no_needs, &query_result);
    for (auto i : query_result) std::cout << i << " ";
    std::cout << std::endl;
    std::cout << "Query \"for AND NOT (drug OR approach)\": " << std::endl;
    std::vector<std::string> needs2{"for"}, no_needs2{"drug", "approach"};
    std::set<int> query_result2;
    Query(inverted_indexes, needs2, no_needs2, &query_result2);
    for (auto i : query_result2) std::cout << i << " ";
    std::cout << std::endl;
}
