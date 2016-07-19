// --------------------------
//  projects/c++/graph/Graph.h
// Copyright (C) 2016
// Glenn P. Downing
// --------------------------

#ifndef Graph_h
#define Graph_h

// --------
// includes
// --------

#include <cassert> // assert
#include <cstddef> // size_t
#include <utility> // make_pair, pair
#include <vector>  // vector
#include <functional>
#include <iostream>


using namespace std;

// -----
// Graph
// -----

class Graph {
    public:
        // --------
        // typedefs
        // --------

        typedef int vertex_descriptor;                                        // fix!
        typedef pair<vertex_descriptor,vertex_descriptor> edge_descriptor;    // fix!

        typedef vector<vertex_descriptor>::const_iterator vertex_iterator;          // fix!
        typedef vector<edge_descriptor>  ::const_iterator edge_iterator;            // fix!
        typedef vector<vertex_descriptor>::const_iterator adjacency_iterator;       // fix!

        typedef std::size_t vertices_size_type;
        typedef std::size_t edges_size_type;

    public:
        // --------
        // add_edge
        // --------

        /**
         * <your documentation>
         */
        friend std::pair<edge_descriptor, bool> add_edge (vertex_descriptor u, vertex_descriptor v, Graph& g) {
            // <your code>
            edge_descriptor ed = std::make_pair(u,v);
            bool to_be_added = true;                            //do we need to add edge (if duplicate, no. if first time, yes) default we assume yes
            bool added = false;                                 //was the edge added, be defaul we say no
            vector<vertex_descriptor> adj_list = g.graph[u];
            auto b = adj_list.begin();                          //beginning of u's vector
            auto e = adj_list.end();                            //end of u's vector
            while(b != e)
            {
                if(*b == v)                                     //is member equal to v
                    to_be_added = false;                        //edge already exist so lets not add another in later
                ++b;
            }                                         
            if(to_be_added)                                     //ed needs to be added
            {
                g.graph[u].push_back(v);                        //add v to u's adjacency list
                g.m.push_back(ed);                              //add ed to the vector of edges in g
                added = true;
            }                                                    
            return std::make_pair(ed, added);}

        // ----------
        // add_vertex
        // ----------

        /**
         * <your documentation>
         */
        friend vertex_descriptor add_vertex (Graph& g) {
            // <your code>
            vertex_descriptor v = g.graph.size(); // fix
            g.n.push_back(v);
            g.graph.push_back(vector<vertex_descriptor>());
            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * <your documentation>
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vd, const Graph& g) {
            // <your code>
            adjacency_iterator b = g.graph[vd].begin();
            adjacency_iterator e = g.graph[vd].end();
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * <your documentation>
         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor u, vertex_descriptor v, const Graph& g) {
            // <your code>
            edge_descriptor ed = std::make_pair(u,v);
            bool exist = false;
            auto b = g.m.begin();
            auto e = g.m.end();
            while(b!=e)
            {
                if(*b==ed)
                    exist=true;
                ++b;
            }                  
            return std::make_pair(ed, exist);}

        // -----
        // edges
        // -----

        /**
         * <your documentation>
         */
        friend std::pair<edge_iterator, edge_iterator> edges (const Graph& g) {
            // <your code>
            edge_iterator b = g.m.begin();
            edge_iterator e = g.m.end();
            return std::make_pair(b, e);}

        // ---------
        // num_edges
        // ---------

        /**
         * <your documentation>
         */
        friend edges_size_type num_edges (const Graph& g) {
            // <your code>
            edges_size_type s = g.m.size(); // fix
            return s;}

        // ------------
        // num_vertices
        // ------------

        /**
         * <your documentation>
         */
        friend vertices_size_type num_vertices (const Graph& g) {
            // <your code>
            vertices_size_type s = g.n.size(); // fix
            return s;}

        // ------
        // source
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor source (edge_descriptor ed, const Graph& g) {
            // <your code>
            vertex_descriptor vd = ed.first; // fix
            return vd;}

        // ------
        // target
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor target (edge_descriptor ed, const Graph& g) {
            // <your code>
            vertex_descriptor vd = ed.second; // fix
            return vd;}

        // ------
        // vertex
        // ------

        /**
         * <your documentation>
         */
        friend vertex_descriptor vertex (vertices_size_type x, const Graph& g) {
            // <your code>
            vertex_descriptor vd = g.n[x]; // fix
            return vd;}

        // --------
        // vertices
        // --------

        /**
         * <your documentation>
         */
        friend std::pair<vertex_iterator, vertex_iterator> vertices (const Graph& g) {
            // <your code>
            vertex_iterator b = g.n.begin();
            vertex_iterator e = g.n.end();
            return std::make_pair(b, e);}

    private:
        // ----
        // data
        // ----

        std::vector< std::vector<vertex_descriptor> > graph; //vector of vectors to represent an adjacency list for vertices 
        std::vector<vertex_descriptor> n;                     //vector for the vertices
        std::vector<edge_descriptor> m;                       //vector for the edges


        // -----
        // valid
        // -----

        /**
         * <your documentation>
         */
        bool valid () const 
        {
            // <your code>
            if(graph.size() > n.size())
                return false;
            return true;
        }

    public:
        // ------------
        // constructors
        // ------------

        /**
         * <your documentation>
         */
        Graph (std::vector<std::vector<vertex_descriptor> > g1 = std::vector<std::vector<vertex_descriptor> >(),
               std::vector<vertex_descriptor> v1 = std::vector<vertex_descriptor>(), 
               std::vector<edge_descriptor> e1 = std::vector<edge_descriptor> ()
              ) :
            graph(g1),
            n(v1),
            m(e1)
        {
            // <your code>
            assert(valid());
        }

        // Default copy, destructor, and copy assignment
        // Graph  (const Graph<T>&);
        // ~Graph ();
        // Graph& operator = (const Graph&);
    };






















#endif // Graph_h
