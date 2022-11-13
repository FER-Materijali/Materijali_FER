using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace TextSearch
{
    public partial class TextSearch : Form
    {
        public TextSearch()
        {
            InitializeComponent();
        }

        private void searchBtn_Click(object sender, EventArgs e)
        {
            resultOut.Clear();

            var searcher = getSearcher();
            var result = searcher.Search(textInput.Text.ToLower(), patternInput.Text.ToLower());

            int lastIndex = 0;
            for(var i = 0; i < result.Count; i++)
            {
                var index = result[i];
                var nextIndex = i < result.Count - 1 ? result[i + 1] : textInput.Text.Length;

                resultOut.AppendText(textInput.Text.Substring(lastIndex, index - lastIndex));
                lastIndex = Math.Min(index + patternInput.Text.Length, textInput.Text.Length);

                resultOut.SelectionFont = new Font(resultOut.Font, FontStyle.Bold);

                var upToIndex = Math.Min(nextIndex, index + patternInput.Text.Length);
                resultOut.AppendText(textInput.Text.Substring(index, upToIndex - index));
                resultOut.SelectionFont = new Font(resultOut.Font, FontStyle.Regular);

                lastIndex = upToIndex;
            }
            resultOut.AppendText(textInput.Text.Substring(lastIndex, textInput.Text.Length - lastIndex));
        }

        private Searcher getSearcher()
        {
            return rabinKarpBtn.Checked ? 
                new RabinKarpSearcher() as Searcher : 
                new KnuthMorrisPrattSearcher() as Searcher;
        }
    }
}
