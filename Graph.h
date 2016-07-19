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
         parameters
            vertex_descriptor u : the first vertex of the edge
            vertex_descriptor v : the second vetex of the edge
            Graph& g            : the graph that we want to add the edge to
        return
            pair<edge_descriptor,bool> : first is the edge that was "added" , second is a bool that said if it was added or not
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
         parameter
            Graph& g : the graph that we want to add the edge to
        return
            vertex_descriptor : the vertex that we added
         */
        friend vertex_descriptor add_vertex (Graph& g) {
            // <your code>
            vertex_descriptor v = g.graph.size();               //the vertex_descriptor will be the size of the graph before the vertex is added
            g.n.push_back(v);                                   //add v to the vector of vertices
            g.graph.push_back(vector<vertex_descriptor>());     //add a new vector for the new vertex
            return v;}

        // -----------------
        // adjacent_vertices
        // -----------------

        /**
         * <your documentation>
        parameter
            vertex_descriptor : the vertex that we want to grab the adjacency "list" for
            Graph&            : the graph that vd belongs to
        return
            pair<adjacency_iterator, adjacency_iterator> first is the begin of the vector for vd, second is the end of the vector for ed
         */
        friend std::pair<adjacency_iterator, adjacency_iterator> adjacent_vertices (vertex_descriptor vd, const Graph& g) {
            // <your code>
            adjacency_iterator b = g.graph[vd].begin();     //the start of the vector for vd
            adjacency_iterator e = g.graph[vd].end();       //the end of the vector for vd
            return std::make_pair(b, e);}

        // ----
        // edge
        // ----

        /**
         * <your documentation>
         parameters
            vertex_descriptor u : the first vertex of the edge
            vertex_descriptor v : the second vetex of the edge
            Graph& g            : the graph that we want to add the edge to
        return
            pair<edge_descriptor,bool> : first is the edge that we are looking for , second is a bool that said if it was existed or not

         */
        friend std::pair<edge_descriptor, bool> edge (vertex_descriptor u, vertex_descriptor v, const Graph& g) {
            // <your code>
            edge_descriptor ed = std::make_pair(u,v);           //the edge
            bool exist = false;                                 //does it exist?
            auto b = g.m.begin();                               //beginning of the vector of edges
            auto e = g.m.end();                                 //end of the vector of edges
            while(b!=e)
            {
                if(*b==ed)                                      //check to see if ed is already in vector
                    exist=true;                                 //if so it exist
                ++b;
            }                  
            return std::make_pair(ed, exist);}

        // -----
        // edges
        // -----

        /**
         * <your documentation>
         parameter
            Graph&            : the graph that we are looking at
        return
            pair<edge_iterator, edge_iterator> first is the begin of the vector for vd, second is the end of the vector for ed
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
         purpose
            to find the number of edges
         parameter
            Graph& : the graph we are looking at
        return 
            edges_size_type : the number of edges in g
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
        purpose
            to find the number of vertices
        parameter
            Graph& : the graph we are looking at
        return 
            vertices_size_type : the number of vertices in g
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
        purpose
            to find the source of a directed edge
        parameters
            edge_descriptor : the edge we want to find the source of
            Graph&          : the graph we are looking in
        return
            vertex descriptor : the source vertex
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
        purpose
            to find the targer of a directed edge
        parameters
            edge_descriptor : the edge we want to find the targer of
            Graph&          : the graph we are looking in
        return
            vertex descriptor : the target vertex
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
        purpose
            to get the xth vertex
        parameter
            vectices_size_type : the vertex index we are looking for
            Graph&             : the graph we are looking in
        return
            vertex_descriptor : the vetrex at that index
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
        purpose
            to provide the beginning and end of the vector of vertices
        parameters
            Graph& : the graph we are looking at
        return
            pair <vertex_iterator, vertex_iterator> : first is the beginning of the vector for vertices, second is the end of the vector of vertices
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
        purpose
            confirm the a graph is valid
        parameters
            none
        return
            true is the graph is valid , false otherwise
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
         parameter
            vector<vector> : existing vertices' adjacency vectors
            vector<>       : existing vertices
            vector<>       : exisitng edges 
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
