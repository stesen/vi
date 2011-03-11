all: view

report:clean
	xelatex vi
	bibtex  vi
	xelatex vi
	xelatex vi

view: report
	okular vi.pdf 2> /dev/null

clean:
	@rm -vfr *.pdf *.out *.log *.toc *.aux *.bak *.bbl *.blg
