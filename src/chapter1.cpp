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
		std::map< std::pair<std::string, int>, std::vector<int> > *inverted_indexes) {
	int left = 0;
	while (left < term_documentsid.size()) {
		int right = left;
		std::vector<int> doc_ids;
		while (right < term_documentsid.size() &&
			term_documentsid[left].first == term_documentsid[right].first) {
			doc_ids.push_back(term_documentsid[right].second);
            ++right;
		} // end while
		inverted_indexes->insert({ {term_documentsid[left].first, right - left}, doc_ids });
		left = right;
	} // end while
}

static void PrintInvertedIndexes(const std::map< std::pair<std::string, int>, std::vector<int> > &inverted_indexes) {
	for (const auto &p : inverted_indexes) {
		std::cout << "( " << p.first.first << ", " << p.first.second << " ): ";
		for (auto i : p.second) std::cout << i << " ";
		std::cout << std::endl;
	}
}

void TestC1E1() {
	std::string file_path = "./../data/1.1.txt";
	std::vector< std::pair<std::string, int> > term_documentsid;
	std::map< std::pair<std::string, int>, std::vector<int> > inverted_indexes;
	ReadData(file_path, &term_documentsid);
	Sort(&term_documentsid);
	GenerateInvertedIndexes(term_documentsid, &inverted_indexes);
	PrintInvertedIndexes(inverted_indexes);
}

void TestC1E2() {

}

void TestC1E3() {

}
