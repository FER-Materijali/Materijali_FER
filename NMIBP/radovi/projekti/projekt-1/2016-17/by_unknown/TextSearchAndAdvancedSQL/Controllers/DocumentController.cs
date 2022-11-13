using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;
using TextSearchAndAdvancedSQL.BLL.Model;
using TextSearchAndAdvancedSQL.BLL.UC;
using TextSearchAndAdvancedSQL.Models.Document;

namespace TextSearchAndAdvancedSQL.Controllers
{
    public class DocumentController : Controller
    {
        // GET: Search
        public ActionResult Index()
        {
            return RedirectToAction(nameof(Search));
        }

        public ActionResult Details(int id)
        {
            return View(new GetDocumentUseCase().Execute(id));
        }

        // GET: AddText
        public ActionResult AddText()
        {
            return View(new AddTextVM());
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult AddText(AddTextVM vm)
        {
            var doc = new Document();
            try { doc.Title = vm.Title; } catch (Exception e) { ModelState.AddModelError(nameof(AddTextVM.Title), e.Message); }
            try { doc.Summary = vm.Summary; } catch (Exception e) { ModelState.AddModelError(nameof(AddTextVM.Summary), e.Message); }
            try { doc.Keywords = vm.Keywords; } catch (Exception e) { ModelState.AddModelError(nameof(AddTextVM.Keywords), e.Message);  }
            try { doc.Body = vm.Body; } catch (Exception e) { ModelState.AddModelError(nameof(AddTextVM.Body), e.Message); }

            if(!ModelState.IsValid)
            {
                return View(vm);
            }

            if (new AddTextUseCase().Execute(doc))
            {
                return RedirectToAction(nameof(Search), new { title = doc.Title });
            }
            else
            {
                return View(vm);
            }
        }

        // GET: Search
        public ActionResult Search(string title = "")
        {
            return View(new SearchVM { Patterns = title, Operator = "and", SearchType = "semantic" });
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Search(SearchVM vm)
        {
            var patterns = vm.Patterns.Split('"')
                     .Select((element, index) => index % 2 == 0  // If even index
                                           ? element.Split(new[] { ' ' }, StringSplitOptions.RemoveEmptyEntries)  // Split the item
                                           : new string[] { element })  // Keep the entire item
                     .SelectMany(element => element).ToList();
            var op = "and".Equals(vm.Operator, StringComparison.InvariantCultureIgnoreCase) ? SearchUseCase.Operator.And : SearchUseCase.Operator.Or;

            SearchUseCase.Response response = null;
            if ("semantic".Equals(vm.SearchType, StringComparison.InvariantCultureIgnoreCase))
            {
                response = new SemanticSearchUseCase().Execute(patterns, op);
            }
            else
            {
                response = new FuzzySearchUseCase().Execute(patterns, op);
            }

            vm.SQLQuery = response.SQLQuery;

            vm.Documents = (from d in response.Results
                            select new SearchVM.Document
                            {
                                Id = d.Item1,
                                Title = d.Item2,
                                Rank = d.Item3,
                            }).ToList();

            return View(vm);
        }

        // GET: Analyze
        public ActionResult Analyze()
        {
            return View(new AnalyzeVM());
        }

        [HttpPost]
        [ValidateAntiForgeryToken]
        public ActionResult Analyze(AnalyzeVM vm)
        {
            var gran = "day".Equals(vm.Granulation, StringComparison.InvariantCultureIgnoreCase) ? AnalyzeUseCase.Granulation.Days : AnalyzeUseCase.Granulation.Hours;
            vm.Response = new AnalyzeUseCase().Execute(vm.Start, vm.End, gran);
            return View(vm);
        }
    }
}