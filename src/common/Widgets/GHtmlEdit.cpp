#include "Lgi.h"
#include "GHtmlEdit.h"
#include "GHtmlPriv2.h"
#include "GSkinEngine.h"
#include "GCombo.h"
#include "GScrollBar.h"

#define IDC_STYLE					100
#define IDC_FONT					101
#define IDC_POINTSIZE				102
#define IDC_BOLD					103
#define IDC_ITALIC					104
#define IDC_UNDERLINE				105

#define TOOLBAR_HT					18

#define	TAB_STOP					0

#define SubtractPtr(a, b)			( (((int)(a))-((int)(b))) / sizeof(*a) )

using namespace Html2;

uint32 IconData[] =
{	
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0x00000000, 0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0x08610861, 0x08610861, 0xFFFF8C51, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0861FFFF, 0x08610861, 0x08610861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x6FE16FE1, 0xFE616FE1, 0xFE61FE61, 0x0000FB61, 0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0x08610861, 0x08610861, 0x8C510861, 
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0861FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000FFFF, 0x0FF90FF9, 0x6FE16FE1, 0xFE616FE1, 0xFE61FE61, 0xFB61FB61, 0x0000FB61, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x52AAFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000FFFF, 0x0FF90FF9, 0x6FE16FE1, 0xFE616FE1, 0xFB61FE61, 0xFB61FB61, 0x0000F861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0xFFFFFFFF, 0x8C51FFFF, 0x8C510861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 
	0xFFFFFFFF, 0xFFFFFFFF, 0x9CD3DEFB, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0x0FF90000, 0x0FF90FF9, 0x6FE10FF9, 0xDEFB6FE1, 0xDEFBDEFB, 0xF861FB61, 0xF861F861, 0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0x08610861, 0x08610861, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xDEFB632C, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0x0FF90000, 0x0FF90FF9, 0xDEFB0FF9, 0xDEFBDEFB, 0xDEFBDEFB, 0xF861DEFB, 0xF861F861, 0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0x08610861, 0x08610861, 0x08610861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF632C, 
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0x0B7F0000, 0x0B7F0B7F, 0xDEFBDEFB, 0xDEFBDEFB, 0x00000000, 0xDEFBDEFB, 0xF861F861, 0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0xFFFFFFFF, 0xFFFFFFFF, 0x08618C51, 0xFFFF8C51, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x9CD3FFFF, 0xFFFFDEFB, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0x0B7F0000, 0x0B7F0B7F, 0xDEFBDEFB, 0x0000DEFB, 0xFFFFFFFF, 0xDEFB0000, 0x0000DEFB, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0xFFFFFFFF, 0xFFFFFFFF, 0x08618C51, 0xFFFF8C51, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x52AAFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 
	0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0x0B7F0000, 0x087F087F, 0xDEFB087F, 0x0000DEFB, 0xFFFFFFFF, 0xDEFB0000, 0x0000DEFB, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0x08610861, 0x08610861, 0x08610861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0861FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0861FFFF, 0xFFFFFFFF, 0x0861FFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000FFFF, 0x087F087F, 0xDEFB087F, 0xDEFBDEFB, 0x00000000, 0x0000DEFB, 0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x08610861, 0x08610861, 0x08610861, 0xFFFF8C51, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0861FFFF, 0x08610861, 0x08610861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 
	0xFFFFFFFF, 0x08610861, 0xFFFF0861, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0000FFFF, 0x087F087F, 0xC87FC87F, 0xDEFBC87F, 0xDEFBDEFB, 0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0xC87FC87F, 0xDEFBC87F, 0x0000DEFB, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x632CFFFF, 0x00000000, 0x00000000, 0x00000000, 
	0x632C0000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x00000000, 0x00000000, 0xFFFF0000, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 
};
GInlineBmp Icons = { 64, 16, 16, IconData };

bool CanHaveText(HtmlTag TagId)
{
	switch (TagId)
	{
		case TAG_TABLE:
		case TAG_TR:
		case TAG_BR:
		case TAG_HR:
		case TAG_BODY:
		case TAG_HTML:
			return false;
	}

	return true;
}

class Btn : public GLayout
{
	int Val;
	int Icon;
	GImageList *Img;
	int HasLeft;
	int HasRight;
	bool Toggle;

public:
	Btn(int cmd, int ico, bool toggle, GImageList *img, int wid)
	{
		Val = 0;
		SetId(cmd);
		Icon = ico;
		Img = img;
		HasLeft = -1;
		HasRight = -1;
		Toggle = toggle;
		
		GRect r(0, 0, wid-1, TOOLBAR_HT);
		SetPos(r);
		SetTabStop(TAB_STOP);
	}

	int64 Value()
	{
		return Val;
	}

	void Value(int64 v)
	{
		Val = v;
		Invalidate();
	}

	void OnPaint(GSurface *pDC)
	{
		if (HasLeft < 0 || HasRight < 0)
		{
			GViewIterator *i = GetParent()->IterateViews();
			if (i)
			{
				HasLeft = false;
				HasRight = false;

				GRect Pos = GetPos();

				for (GViewI *c = i->First(); c; c = i->Next())
				{
					GRect CPos = c->GetPos();
					if (CPos.x2 == Pos.x1 - 1)
					{
						HasLeft = true;
					}
					if (CPos.x1 == Pos.x2 + 1)
					{
						HasRight = true;
					}
				}

				DeleteObj(i);
			}
		}

		GRect Back = GetClient();
		if (HasLeft)
		{
			Back.x1 -= 40;
		}
		if (HasRight)
		{
			Back.x2 += 40;
		}
		
		GMemDC Mem(X(), Y(), 32);
		Mem.Colour(LC_MED, 24);
		Mem.Rectangle();

		GSkinEngine *s = LgiApp->SkinEngine;
		if (s)
		{
			s->DrawBtn(&Mem, Back, Val, Enabled());
		}
		else
		{
			LgiWideBorder(&Mem, Back, Val ? SUNKEN : RAISED);
		}

		if (HasLeft && Val)
		{
			Mem.Colour(Rgb24(0x72, 0x72, 0x72), 24);
			Mem.Line(0, 0, 0, Y()-1);
			Mem.Colour(Rgb24(0xa0, 0xa0, 0xa0), 24);
			Mem.Line(1, 1, 1, Y()-2);
		}

		if (Img)
		{
			GRect r(0, 0, Img->TileX()-1, Img->TileY()-1);
			r.Offset(((X()-Img->TileX())>>1)+Val, ((Y()-Img->TileY())>>1)+Val);
			Mem.Colour(Rgb24(255, 0, 0), 24);
			if (HasLeft && !HasRight)
			{
				// Right end
				r.Offset(-2, 0);
			}
			else if (!HasLeft && HasRight)
			{
				// Left end
				r.Offset(2, 0);
			}
			Img->Draw(&Mem, r.x1, r.y1, Icon);
		}

		pDC->Blt(0, 0, &Mem);
	}

	void OnMouseClick(GMouse &m)
	{
		if (m.Left())
		{
			Capture(m.Down());
			if (!Toggle)
			{
				Value(m.Down());
			}

			if (!m.Down() && GetClient().Overlap(m.x, m.y))
			{
				// Post msg.
				SendNotify();
			}
		}
	}

	void OnMouseMove(GMouse &m)
	{
		if (!Toggle && IsCapturing())
		{
			int v = GetClient().Overlap(m.x, m.y);
			if (v != Val)
			{
				Value(v);
			}
		}
	}
};

struct Block : public GRect
{
	GTag *t;
	GFlowRect *fr;

	bool OverlapX(int x) { return x >= x1 && x <= x2; }
	bool OverlapY(int y) { return y >= y1 && y <= y2; }
	bool OverlapX(Block *b) { return !(b->x2 < x1 || b->x1 > x2); }
	bool OverlapY(Block *b) { return !(b->y2 < y1 || b->y1 > y2); }

	int StartOffset()
	{
		int Chars = 0;
		for (GFlowRect *r = t->PreText() ? t->TextPos[1] : t->TextPos.First();
			r; r=t->TextPos.Next())
		{
			if (r == fr)
			{
				return Chars;
			}

			Chars += r->Len;
		}

		return 0;
	}

	int EndOffset()
	{
		int Chars = 0;
		for (GFlowRect *r = t->PreText() ? t->TextPos[1] : t->TextPos.First();
			r; r=t->TextPos.Next())
		{
			if (r == fr)
			{
				return Chars + r->Len;
			}

			Chars += r->Len;
		}

		return 0;
	}
};

#if 1
class HtmlEdit : public GHtml2, public GDefaultDocumentEnv
{
	GTag *b;
	GArray<Block> Blocks;
	GHtmlEdit *Edit;

	void BlockTag(GTag *t)
	{
		// Creates a block for each run of text we know about. This is then used for doing
		// cursoring around.
		int n = 0;
		for (GFlowRect *Tr=t->TextPos.First(); Tr; Tr=t->TextPos.Next(), n++)
		{
			if (t->PreText() && !n)
			{
				if (!ValidStrW(t->Text()))
				{
					Block *b = &Blocks[Blocks.Length()];
					int x = t->AbsX();
					int y = t->AbsY();
					b->Set(x + Tr->x2, y + Tr->y1, x + Tr->x2 + 1, y + Tr->y2 - 1);
					b->t = t;
					break;
				}

				continue;
			}

			Block *b = &Blocks[Blocks.Length()];
			int x = t->AbsX();
			int y = t->AbsY();
			(GRect&)*b = (GRect&)*Tr;
			b->Offset(x, y);
			b->t = t;
			b->fr = Tr;
		}

		// Run through children
		for (GTag *c = t->Tags.First(); c; c = t->Tags.Next())
		{
			BlockTag(c);
		}
	}

	void BuildBlocks()
	{
		// Rebuild the block list from scratch.
		Blocks.Length(0);
		BlockTag(Tag);
	}

	Block *GetBelow(int x, int y)
	{
		// Gets the next block below the x,y point. Usually used when the user
		// cursors down.
		Block *Close = 0;
		for (int i=0; i<Blocks.Length(); i++)
		{
			Block *b = &Blocks[i];
			if (!b->Overlap(x, y) &&
				b->y1 > y)
			{
				if (!Close)
				{
					Close = b;
				}
				else
				{
					if (b->OverlapY(Close))
					{
						if (b->OverlapX(x) &&
							!Close->OverlapX(x))
						{
							Close = b;
						}
					}
					else if (b->y1 < Close->y1)
					{
						Close = b;
					}
				}
			}
		}
		return Close;
	}

	Block *GetAbove(int x, int y)
	{
		// Gets the next block above the x,y point. Usually used when the user
		// cursors up.
		Block *Close = 0;
		for (int i=0; i<Blocks.Length(); i++)
		{
			Block *b = &Blocks[i];
			if (b->y2 < y)
			{
				if (!Close)
				{
					Close = b;
				}
				else
				{
					if (b->OverlapY(Close))
					{
						if (b->OverlapX(x) &&
							!Close->OverlapX(x))
						{
							Close = b;
						}
					}
					else if (b->y1 > Close->y1)
					{
						Close = b;
					}
				}
			}
		}
		return Close;
	}

	Block *GetLeft(int x, int y)
	{
		// Gets the next block to the left of the x,y point. Usually used when the user
		// cursors left.
		Block *Close = 0;
		for (int i=0; i<Blocks.Length(); i++)
		{
			Block *b = &Blocks[i];
			if (!b->Overlap(x, y))
			{
				if (b->OverlapY(y))
				{
					if (b->x2 < x)
					{
						if (!Close || (b->x2 > Close->x2))
						{
							Close = b;
						}
					}
				}
				else if (b->y2 < y)
				{
					if (!Close)
					{
						Close = b;
					}
					else if (Close->OverlapY(b->y2))
					{
						if (b->x1 > Close->x2)
						{
							Close = b;
						}
					}
					else if (b->y1 > Close->y2)
					{
						Close = b;
					}
				}
			}
		}
		return Close;
	}

	Block *GetRight(int x, int y)
	{
		// Gets the next block to the right of the x,y point. Usually used when the user
		// cursors right.
		Block *Close = 0;
		for (int i=0; i<Blocks.Length(); i++)
		{
			Block *b = &Blocks[i];
			if (!b->Overlap(x, y))
			{
				if (b->OverlapY(y))
				{
					// Same line
					if (b->x1 > x)
					{
						// On the right
						if (!Close || (b->x1 < Close->x1))
						{
							Close = b;
						}
					}
				}
				else if (b->y1 > y)
				{
					// Below
					if (!Close)
					{
						Close = b;
					}
					else if (Close->OverlapY(b->y1))
					{
						// Close and b are on the same line
						if (b->x2 < Close->x1)
						{
							// b is furthur left, which is what we want
							Close = b;
						}
					}
					else if (b->y2 < Close->y1)
					{
						// b is above Close
						Close = b;
					}
				}
			}
		}
		return Close;
	}

public:
	HtmlEdit(GHtmlEdit *edit) : GHtml2(100, 0, 0, 100, 100)
	{
		// Construct the basics
		SetReadOnly(false);
		Edit = edit;
		b = 0;
		SetEnv(this);
		Sunken(true);
		SetTabStop(true);
		Name("<html><body></body></html>");
	}

	void OnDocumentChange()
	{
		Edit->SendNotify(GTVN_DOC_CHANGED);
	}

	#ifdef _DEBUG
	// Draw a red box around the cursor for debugging.
	void OnPaint(GSurface *pDC)
	{
		GHtml2::OnPaint(pDC);

		int LineY = GetFont()->GetHeight();
		int sx, sy;
		GetScrollPos(sx, sy);
		GRect c = GetCursorPos();
		c.Offset(0, -LineY*sy);
		c.Size(-1, -1);
		pDC->Colour(Rgb24(255, 0, 0), 24);
		pDC->Box(&c);
	}
	#endif

	bool IsSameStyle(GTag *a, GTag *b)
	{
		bool Status = false;

		if (a && b)
		{
			if (a->TagId == b->TagId)
			{
				if (a->Font && b->Font)
				{
					char *af = a->Font->Face();
					char *bf = b->Font->Face();
					if (af && bf)
					{
						Status = stricmp(af, bf) == 0;
						Status &= a->Font->PointSize() == b->Font->PointSize();
						Status &= a->Font->Bold() == b->Font->Bold();
						Status &= a->Font->Underline() == b->Font->Underline();
						Status &= a->Font->Italic() == b->Font->Italic();
					}
				}
				else
				{
					Status = true;
				}
			}
		}

		return Status;
	}

	void Optimize(GTag *Tag)
	{
		if (Tag)
		{
			bool Changed = false;

			// Look through direct children and remove unneccessary complexity
			GArray<GTag*> t;
			for (GTag *c = Tag->Tags.First(); c; c = Tag->Tags.Next())
			{
				t.Add(c);
			}
			
			for (int i=0; i<t.Length()-1; i++)
			{
				GTag *a = t[i];
				GTag *b = t[i+1];
				if (IsSameStyle(a, b))
				{
					int LenA = StrlenW(a->Text());
					int LenB = StrlenW(b->Text());
					char16 *Txt = new char16[LenA + LenB + 1];
					if (Txt)
					{
						if (a->Text())
							StrcpyW(Txt, a->Text());
						if (b->Text())
							StrcpyW(Txt + LenA, b->Text());
						a->Text(Txt);

						if (b == Cursor &&
							b->Cursor >= 0)
						{
							// Ah! We're about to delete the tag that the cursor points at...
							// better move it:
							a->Cursor = LenA + b->Cursor;
							b->Cursor = -1;
							Cursor = a;
						}
						
						b->Detach();
						DeleteObj(b);
						
						t.DeleteAt(i + 1, true);
						i--;						
						Changed = true;
					}
				}
			}

			if (Changed)
			{
				ViewWidth = -1;
			}
		}
	}

	GTag *GetStyleInsertPoint(GTag *Cur, int *Idx)
	{
		if (Cur)
		{
			GTag *Prev = 0;
			for (GTag *t = Cur; t; t = t->Parent)
			{
				if (t->TagId == TAG_B ||
					t->TagId == TAG_U ||
					t->TagId == TAG_I ||
					t->TagId == TAG_TD ||
					t->IsBlock)
				{
					if (Idx)
					{
						*Idx = Prev ? t->Tags.IndexOf(Prev) : 0;
					}

					return t;
				}

				Prev = t;
			}
		}

		return 0;
	}

	template <typename T>
	bool HasStyle(GCss::PropType s, GArray<T> &Values)
	{
		bool CursorFirst = IsCursorFirst();

		if (Cursor && Selection)
		{
			GTag *Min = CursorFirst ? Cursor : Selection;
			GTag *Max = CursorFirst ? Selection : Cursor;

			for (GTag *t = Min; t; t = NextTag(t))
			{
				T *v = (T*) t->PropAddress(s);
				if (v)
				{
					Values.Add(*v);
				}

				if (t == Max)
					break;
			}
		}
		else if (Cursor)
		{
			T *v = (T*) Cursor->PropAddress(s);
			if (v)
			{
				Values.Add(*v);
			}
		}

		return Values.Length() > 0;
	}

	bool IsStyled(GTag *Tag, char *Style)
	{
		if (!Tag || !Style || !Tag->Tag)
			return false;

		return stricmp(Tag->Tag, Style) == 0;
	}

	bool StylizeSelection(GCss &Style)
	{
		if (!Cursor || !Selection)
			return false;

		bool CursorFirst = IsCursorFirst();
		GTag *MinTag, *MaxTag, *t;
		int MinIdx, MaxIdx;
		if (CursorFirst)
		{
			MinTag = Cursor;
			MinIdx = Cursor->Cursor;
			MaxTag = Selection;
			MaxIdx = Selection->Selection;
		}
		else
		{
			MaxTag = Cursor;
			MaxIdx = Cursor->Cursor;
			MinTag = Selection;
			MinIdx = Selection->Selection;
		}

		if (!MinTag->Parent)
		{
			LgiAssert(!"Huh?");
			return false;
		}

		if (MinTag == MaxTag)
		{
			// Single tag change
			int Idx = MinTag->Parent->Tags.IndexOf(MinTag);
			int Start = MinTag->GetTextStart();
			int Len = StrlenW(MinTag->Text());

			if (MinIdx > Start)
			{
				// Starting partially into the tag...
				GTag *Edit = new GTag(this, 0);
				Edit->Text(NewStrW(MinTag->Text() + MinIdx + Start, MaxIdx - MinIdx));
				Edit->SetTag("span");
				Edit->CopyStyle(Style);

				MinTag->Parent->Attach(Edit, ++Idx);

				if (MaxIdx + Start < Len)
				{
					GTag *After = new GTag(this, 0);
					After->Text(NewStrW(MinTag->Text() + MaxIdx + Start));
					MinTag->Parent->Attach(After, ++Idx);
				}

				MinTag->Text()[MinIdx + Start] = 0;

				// Deselect...
				Cursor->Cursor = -1;
				Selection->Selection = -1;

				// Reselect new tag
				Cursor = Selection = Edit;
				Selection->Selection = 0;
				Cursor->Cursor = StrlenW(Selection->Text());
			}
			else if (MaxIdx < Len - Start)
			{
				// Starting from the start of the tag... but not the whole thing
				GTag *Edit = new GTag(this, 0);
				Edit->Text(NewStrW(MinTag->Text() + MinIdx + Start, MaxIdx - MinIdx));
				Edit->SetTag("span");
				Edit->CopyStyle(Style);
				MinTag->Parent->Attach(Edit, Idx);

				char16 *e = MinTag->Text() + Start + MaxIdx;
				memmove(MinTag->Text(), e, (StrlenW(e) + 1) * sizeof(*e));

				// Deselect...
				Cursor->Cursor = -1;
				Selection->Selection = -1;

				// Reselect new tag
				Cursor = Selection = Edit;
				Selection->Selection = 0;
				Cursor->Cursor = StrlenW(Selection->Text());
			}
			else
			{
				// The whole tag is changing...
				MinTag->CopyStyle(Style);
				if (!MinTag->Tag)
					MinTag->SetTag("span");
				MinTag->Font = 0;
			}
		}
		else
		{
			// Do partial start tag change...


			// Do whole middle tags


			// Do partial end tag change...
		}

		return true;
	}

	bool HasBold()
	{
		GArray<GCss::FontWeightType> Types;
		HasStyle(GCss::PropFontWeight, Types);
		for (int i=0; i<Types.Length(); i++)
		{
			if (Types[i] != GCss::FontWeightNormal &&
				Types[i] != GCss::FontWeightInherit &&
				Types[i] != GCss::FontWeightLighter)
			{
				return true;
			}
		}

		return false;
	}

	bool HasItalic()
	{
		GArray<GCss::FontStyleType> Types;
		HasStyle(GCss::PropFontStyle, Types);
		for (int i=0; i<Types.Length(); i++)
		{
			if (Types[i] == GCss::FontStyleItalic)
				return true;
		}

		return false;
	}

	bool HasUnderline()
	{
		GArray<GCss::TextDecorType> Types;
		HasStyle(GCss::PropTextDecoration, Types);
		for (int i=0; i<Types.Length(); i++)
		{
			if (Types[i] == GCss::TextDecorUnderline)
				return true;
		}

		return false;
	}

	bool OnBold()
	{
		bool Status = false;

		GTag *c = GetCur();
		if (c)
		{
			bool DoUpdate = false;

			if (Selection)
			{
				GCss s;
				s.FontWeight(HasBold() ? GCss::FontWeightNormal : GCss::FontWeightBold);
				DoUpdate = StylizeSelection(s);
			}

			if (DoUpdate)
			{
				DeleteArray(Source);
				Update(true);
				OnDocumentChange();
			}
		}

		LgiAssert(IsOk());
		
		return false;
	}

	bool OnItalic()
	{
		bool Status = false;

		GTag *c = GetCur();
		if (c)
		{
			bool DoUpdate = false;

			if (Selection)
			{
				GCss s;
				s.FontStyle(HasItalic() ? GCss::FontStyleNormal : GCss::FontStyleItalic);
				DoUpdate = StylizeSelection(s);
			}

			if (DoUpdate)
			{
				DeleteArray(Source);
				Update(true);
				OnDocumentChange();
			}
		}

		LgiAssert(IsOk());

		return Status;
	}

	bool OnUnderline()
	{
		bool Status = false;

		GTag *c = GetCur();
		if (c)
		{
			bool DoUpdate = false;

			if (Selection)
			{
				GCss s;
				s.TextDecoration(HasUnderline() ? GCss::TextDecorNone : GCss::TextDecorUnderline);
				DoUpdate = StylizeSelection(s);
			}

			if (DoUpdate)
			{
				DeleteArray(Source);
				Update(true);
				OnDocumentChange();
			}
		}

		LgiAssert(IsOk());

		return Status;
	}

	GTag *GetCur()
	{
		// Gets the current cursor or sets a default one up.
		if (!Cursor)
		{
			GTag *t = Tag ? Tag->GetTagByName("html") : 0;
			if (t = t ? t->GetTagByName("body") : 0)
			{
				for (GTag *c = t->Tags.First(); c; c = t->Tags.Next())
				{
					if (CanHaveText(c->TagId))
					{
						Cursor = c;
						Cursor->Cursor = 0;
						break;
					}
				}
			}

			LgiAssert(Cursor);
		}

		return Cursor;
	}

	void Update(bool IsEdit)
	{
		// Updates the HTML control
		if (IsEdit)
		{
			// An edit occured..

			// Make the cursor visible
			SetCursorVis(true);
			Edit->SetIgnorePulse(true);

			// Reflow the page
			ViewWidth = -1;

			// Rebuild the block list...
			Blocks.Length(0);
		}

		// Update the screen
		Invalidate();
	}

	bool IsEditable(GTag *t)
	{
		// Returns true if the tag is editable
		return	t->TagId == TAG_LI ||
				t->Text();
	}

	void OnCursorChanged()
	{
		if (GetParent())
		{
			GetParent()->SetCtrlValue(IDC_BOLD, HasBold());
			GetParent()->SetCtrlValue(IDC_ITALIC, HasItalic());
			GetParent()->SetCtrlValue(IDC_UNDERLINE, HasUnderline());
		}
		
		Invalidate();
	}

	bool GetLine(GTag *t, int idx, GArray<GFlowRect*> &Rects)
	{
		if (!t || idx < 0)
			return false;

		Block *Close = 0;
		for (int i=0; i<Blocks.Length(); i++)
		{
			Block *b = &Blocks[i];
			if (b->t == t)
			{
			}
		}
		return Close;
	}

	void MoveCursor(int Dx, int Dy, bool Selecting = false)
	{
		if (Blocks.Length() == 0)
			BuildBlocks();

		GTag *t = GetCur();
		if (t)
		{
			GTag *NewCur = 0;
			int NewPos = -1;
			LgiAssert(t->Cursor >= 0);

			int Base = t->GetTextStart();
			char16 *Txt = t->Text() + Base;

			int len = StrlenW(Txt);
			if (Dx)
			{
				if (Selection && !Selecting)
				{
					// Deselecting the current selection, move the cursor
					// to one of the selection block's ends.
					int i = -1;
					GTag *t = 0;
					if (Dx < 0)
					{
						if (IsCursorFirst())
						{
							t = Cursor;
							i = Cursor->Cursor;
						}
						else
						{
							t = Selection;
							i = Selection->Selection;
						}
					}
					else
					{
						if (IsCursorFirst())
						{
							t = Selection;
							i = Selection->Selection;
						}
						else
						{
							t = Cursor;
							i = Cursor->Cursor;
						}
					}

					if (t)
					{
						Cursor->Cursor = -1;
						Selection->Selection = -1;
						Cursor = t;
						Cursor->Cursor = i;
						Selection = 0;

						OnCursorChanged();
					}
				}
				else
				{
					// Move along the current tag
					int i = t->Cursor + Dx;
					if (i >= 0)
					{
						if (i <= len)
						{
							NewCur = t;
							NewPos = i;
						}
						else
						{
							// Run off the right edge
							GRect *r = GetCursorPos();
							Block *b = GetRight(r->x1, r->y1 + (r->Y() >> 1));
							if (b)
							{
								NewCur = b->t;
								NewPos = b->StartOffset();
							}
							else
							{
								// No element to the right, so go down
								b = GetBelow(r->x1, r->y1 + (r->Y() >> 1));
								if (b)
								{
									NewCur = b->t;
									NewPos = b->StartOffset();
								}
							}
						}
					}
					else
					{
						// Run off the left edge
						GRect *r = GetCursorPos();
						Block *b = GetLeft(r->x1, r->y1 + (r->Y() >> 1));
						if (b)
						{
							NewCur = b->t;
							NewPos = b->EndOffset();
						}
					}
				}
			}
			else if (Dy)
			{
				GFont *f = t->GetFont();
				if (f)
				{
					Block *b = 0;
					GRect *r = GetCursorPos();

					if (Dy < 0)
					{
						b = GetAbove(r->x1, r->y1);
					}
					else
					{
						b = GetBelow(r->x1, r->y1 + (r->Y() >> 1));
					}

					if (b)
					{
						int Dx = r->x1 - b->x1;
						int Char = 0;
						if (b->fr)
						{
							GDisplayString Ds(f, b->fr->Text);
							Ds.CharAt(b->fr->Len);
						}
						int Start = b->fr ? SubtractPtr(b->fr->Text, b->t->TextPos[b->t->PreText() ? 1 : 0]->Text) : 0;
						NewPos = Start + Char;
						NewCur = b->t;
					}
				}
			}

			if (NewCur)
			{
				// Selection stuff
				if (Selecting && !Selection)
				{
					// Selection is starting, save current cursor as the selection end.
					Selection = Cursor;
					Selection->Selection = Cursor->Cursor;
				}
				else if (!Selecting && Selection)
				{
					// Selection ending...
					Selection->Selection = -1;
					Selection = 0;
				}

				// Set new cursor
				if (t != NewCur)
				{
					t->Cursor = -1;
					Cursor = NewCur;
				}
				Cursor->Cursor = NewPos;

				// Update the window
				SetCursorVis(true);
				Edit->SetIgnorePulse(true);
				OnCursorChanged();

				// Check if we need to scroll the window at all
				if (VScroll)
				{
					LgiYield(); // Cursor position updates on paint

					int LineY = GetFont()->GetHeight();
					int64 Pos = VScroll->Value();
					GRect Client = GetClient();
					GRect c = GetCursorPos();
					c.Offset(0, -Pos * LineY);

					// LgiTrace("cli=%s c=%s\n", Client.GetStr(), c.GetStr());
					if (c.y1 < 0)
					{
						// Scroll up to keep cursor on screen
						int Lines = abs(c.y1 / LineY) + 1;
						VScroll->Value(max(0, Pos - Lines));
					}
					else if (c.y2 > Client.y2)
					{
						// Scroll down to show cursor
						int Lines = (c.y2 - Client.y2) / LineY + 1;
						VScroll->Value(Pos + Lines);
					}
				}
			}
		}
	}

	void OnMouseClick(GMouse &m)
	{
		Edit->SetIgnorePulse(true);
		SetCursorVis(true);
		GHtml2::OnMouseClick(m);

		LgiAssert(IsOk());
	}

	void Insert(char *utf)
	{
		bool Status = false;

		if (!utf)
			return;

		GTag *t = GetCur();
		if (t)
		{
			DeleteArray(Source);

			if (t->Cursor < 0)
			{
				if (Cursor) Cursor->Cursor = -1;
				Cursor = t;
				Cursor->Cursor = 0;
			}

			if (!t->Text())
			{
				t->Text(LgiNewUtf8To16(utf));
				t->Cursor = StrlenW(t->Text());
				Status = true;
			}
			else
			{
				char16 *w = LgiNewUtf8To16(utf);
				if (w)
				{
					int Base = t->GetTextStart();
					int Insert = t->Cursor + Base;
					int NewChars = StrlenW(w);
					int OldChars = StrlenW(t->Text());
					char16 *s = new char16[NewChars+OldChars+1];
					if (s)
					{
						if (Insert > 0)
							memcpy(s, t->Text(), Insert * sizeof(char16));
						memcpy(s + Insert, w, NewChars * sizeof(char16));
						
						int AfterChars = OldChars - Insert;
						if (AfterChars > 0)
						{
							memcpy(s + Insert + NewChars, t->Text() + Insert, AfterChars * sizeof(char16));
						}

						s[NewChars + OldChars] = 0;

						t->Text(s);
						t->Cursor += NewChars;
						Status = true;
					}

					DeleteArray(w);
				}
			}
		}

		if (Status)
		{
			Update(true);
			OnDocumentChange();
		}
	}

	bool DeleteTag(GTag *t, GArray<GTag*> *Others = 0)
	{
		if (t)
		{
			GTag *c;
			while (c = t->Tags.First())
			{
				if (!DeleteTag(c, Others))
				{
					return false;
				}
			}

			t->Text(0);
			if (t->Parent)
			{
				t->Parent->Tags.Delete(t);
			}
			if (Others) Others->Delete(t);
			DeleteObj(t);

			return true;
		}

		return false;
	}

	void Delete(bool Backwards = false)
	{
		bool Status = false;

		GTag *t = GetCur();
		if (t)
		{
			DeleteArray(Source);

			if (Selection)
			{
				if (Cursor->Text() &&
					Selection == Cursor)
				{
					// Delete range within one tag
					int Offset = Cursor->GetTextStart();
					int OldLen = StrlenW(Cursor->Text());
					int DelLen = abs(Cursor->Selection - Cursor->Cursor);
					int NewLen = OldLen - DelLen;
					char16 *NewTxt = new char16[NewLen+1];
					if (NewTxt)
					{
						char16 *s = NewTxt;
						int StartDel = min(Cursor->Selection, Cursor->Cursor) + Offset;
						if (StartDel > 0)
						{
							memcpy(s, Cursor->Text(), sizeof(char16)*StartDel);
							s += StartDel;
						}
						int EndDel = max(Cursor->Selection, Cursor->Cursor) + Offset;
						if (EndDel < OldLen)
						{
							int Chars = OldLen-EndDel;
							memcpy(s, Cursor->Text() + EndDel, sizeof(char16)*(Chars));
							s += Chars;
						}
						*s++ = 0;

						Cursor->Text(NewTxt);
						Cursor->Selection = -1;
						Cursor->Cursor = StartDel - Offset;
						Selection = 0;

						Status = true;
					}
				}
				else
				{
					// Delete over multiple tags.
					
					bool CursorFirst = IsCursorFirst();
					GTag *First = CursorFirst ? Cursor : Selection;
					GTag *Last = CursorFirst ? Selection : Cursor;
					int *FirstMarker = CursorFirst ? &Cursor->Cursor : &Selection->Selection;
					int FirstMarkerValue = *FirstMarker;

					// Delete from first marker to the end of that tag
					int Offset = First->GetTextStart();
					First->Text(NewStrW(First->Text() + Offset, *FirstMarker));
					*FirstMarker = -1;

					// Scan through to the end marker					
					GTag *n = First;
					GArray<GTag*> PostDelete;
					while (n = NextTag(n))
					{
						if (n == Last)
						{
							// Last tag
							Offset = n->GetTextStart();
							int *LastMarker = CursorFirst ? &Selection->Selection : &Cursor->Cursor;
							n->Text(NewStrW(n->Text() + Offset + *LastMarker));
							*LastMarker = -1;
							break;
						}
						else
						{
							// Intermediate tag
							if (!PostDelete.HasItem(n))
								PostDelete.Add(n);
						}
					}

					// Don't delete a parent item of the selection or cursor...
					for (n = Cursor; n; n = n->Parent)
					{
						PostDelete.Delete(n);
					}
					for (n = Selection; n; n = n->Parent)
					{
						PostDelete.Delete(n);
					}

					// Process deletes
					for (int i=0; i<PostDelete.Length(); )
					{
						if (!DeleteTag(PostDelete[i], &PostDelete))
						{
							break;
						}
					}

					Cursor = First;
					Cursor->Cursor = FirstMarkerValue;
					Status = true;
				}
			}
			else if (t->Text())
			{
				int s = t->GetTextStart();
				int Len = StrlenW(t->Text() + s);
				bool End = t->Cursor >= Len;
				if (End && !Backwards)
				{
					GTag *n = t;
					while (n = NextTag(n))
					{
						if (n->TagId == TAG_BR)
						{
							n->Detach();
							DeleteObj(n);
							break;
						}

						if (IsEditable(n))
							break;
					}
					if (n)
					{
						t->Cursor = -1;
						Cursor = t = n;
						if (t)
						{
							t->Cursor = 0;
							
							s = t->GetTextStart();
							Len = StrlenW(t->Text() + s);
							End = t->Cursor >= Len - 1;
						}
					}
				}

				if (Backwards)
				{
					if (t->Cursor > 0)
					{
						t->Cursor--;
					}
					else
					{
						GTag *n = PrevTag(t);

						while (n)
						{
							if (n->TagId == CONTENT &&
								n->Text() &&
								StrlenW(n->Text()) == 0)
							{
								GTag *Del = n;
								n = PrevTag(n);
								Del->Detach();
								DeleteObj(Del);
								continue;
							}
							else if (n->TagId == TAG_BR)
							{
								n->Detach();
								DeleteObj(n);

								if (n = PrevTag(n))
								{
									Cursor->Cursor = -1;
									Cursor = n;
									Cursor->Cursor = StrlenW(Cursor->Text());
								}
								break;
							}

							if (IsEditable(n))
								break;

							n = PrevTag(n);
						}
						if (n)
						{
							t->Cursor = -1;
							Cursor = t = n;
							if (t)
							{
								s = t->GetTextStart();
								t->Cursor = StrlenW(t->Text()) - s - 1;
								if (t->Cursor < 0)
								{
									t = 0;
								}
								else
								{
									Len = StrlenW(t->Text() + s);
									End = t->Cursor >= Len - 1;
								}
							}
						}
					}
				}

				if (t)
				{
					char16 *c = t->Text() + t->Cursor + s;
					if (*c) memmove(c, c + 1, (StrlenW(c + 1) + 1) * sizeof(*t->Text()));
					Status = true;
				}
			}
		}

		if (Status)
		{
			Update(true);
			OnDocumentChange();
		}
	}

	void NewLine()
	{
		bool Status = false;

		GTag *t = GetCur();
		if (t)
		{
			DeleteArray(Source);

			if (Selection)
			{
			}
			else if (t->Text())
			{
				GTag *Insert = t->TagId == CONTENT ? t->Parent : t;
				int Idx = t->TagId == CONTENT && t->Parent ? t->Parent->Tags.IndexOf(t) + 1 : 0;
				int Base = t->GetTextStart();
				int Chars = StrlenW(t->Text());
				int After = Chars - Base - t->Cursor;
				if (After > 0)
				{
					if (Insert)
					{
						GTag *n = new GTag(t->Html, 0);
						if (n)
						{
							n->TagId = CONTENT;
							n->Text(NewStrW(t->Text() + Base + t->Cursor));
							t->Text()[Base + t->Cursor] = 0;
							Insert->Attach(n, Idx);

							Cursor = n;
							Cursor->Cursor = 0;
						}
						t->Cursor = -1;

						n = new GTag(t->Html, 0);
						if (n)
						{
							n->SetTag("br");
							Insert->Attach(n, Idx);
						}

						Status = true;
					}
				}
				else
				{
					GTag *c;
					if (c = new GTag(this, 0))
					{
						c->SetTag("br");
						Insert->Attach(c, Idx++);

						if (c = new GTag(this, 0))
						{
							c->TagId = CONTENT;
							char16 Empty[] = {0};
							c->Text(NewStrW(Empty));
							Insert->Attach(c, Idx++);
							Cursor->Cursor = -1;
							Cursor = c;
							Cursor->Cursor = 0;
							Status = true;
						}
					}
				}
			}
		}

		if (Status)
		{
			Update(true);
			OnDocumentChange();
		}
	}

	bool Cut()
	{
		if (!Selection)
			return false;

		GStringPipe p;

		bool CursorFirst = IsCursorFirst();
		GTag *MinTag = CursorFirst ? Cursor : Selection;
		int MinIdx = CursorFirst ? Cursor->Cursor : Selection->Selection;
		GTag *MaxTag = CursorFirst ? Selection : Cursor;
		int MaxIdx = CursorFirst ? Selection->Selection : Cursor->Cursor;

		if (MinTag == MaxTag)
		{
			if (MinTag->Text())
			{
				int Start = MinTag->GetTextStart();
				p.Push(LgiNewUtf16To8(MinTag->Text() + Start + MinIdx, (MaxIdx - MinIdx) * sizeof(char16)));
			}
		}
		else
		{
			for (GTag *t = MinTag; t; t = NextTag(t))
			{
				char16 *s;
				if (s = t->Text())
				{
					int Start = t->GetTextStart();
					if (t == MinTag)
					{
						p.Push(LgiNewUtf16To8(t->Text() + Start + MinIdx));
					}
					else if (t == MaxTag)
					{
						p.Push(LgiNewUtf16To8(t->Text() + Start, (MaxIdx - Start) * sizeof(char16)));
					}
					else
					{
						p.Push(LgiNewUtf16To8(t->Text() + Start));
					}
				}
				else
				{
					switch (t->TagId)
					{
						case TAG_P:
						case TAG_BR:
						{
							p.Print("\n");
							break;
						}
					}
				}

				if (t == MaxTag)
					break;
			}
		}

		GClipBoard c(this);
		GAutoString txt(p.NewStr());
		c.Text(txt);

		Delete(false);

		return true;
	}

	bool Copy()
	{
		return false;
	}

	bool Paste()
	{
		GClipBoard c(this);
		GAutoString t(c.Text());
		if (t)
		{
			Insert(t);
			return true;
		}

		return false;
	}

	bool OnKey(GKey &k)
	{
		if (k.IsChar)
		{
			if (k.Down())
			{
				if (k.c16 == VK_BACKSPACE)
				{
					if (k.Down())
					{
						Delete(true);
					}
				}
				else if (k.c16 == VK_RETURN)
				{
					if (k.Down())
					{
						NewLine();
					}
				}
				else if (k.c16 >= ' ')
				{
					char *utf = LgiNewUtf16To8(&k.c16, sizeof(k.c16));
					if (utf)
					{
						Insert(utf);
						DeleteArray(utf);
					}
				}
			}
			return true;
		}
		else
		{
			switch (k.c16)
			{
				case VK_HOME:
				{
					if (k.Down())
					{
					}
					return true;
					break;
				}
				case VK_END:
				{
					if (k.Down())
					{
					}
					return true;
					break;
				}
				case VK_DELETE:
				{
					if (k.Down())
					{
						Delete();
					}
					return true;
				}
				case VK_LEFT:
				{
					if (k.Down())
					{
						MoveCursor(-1, 0, k.Shift());
					}
					return true;
					break;
				}
				case VK_RIGHT:
				{
					if (k.Down())
					{
						MoveCursor(1, 0, k.Shift());
					}
					return true;
					break;
				}
				case VK_UP:
				{
					if (k.Down())
					{
						MoveCursor(0, -1, k.Shift());
					}
					return true;
					break;
				}
				case VK_DOWN:
				{
					if (k.Down())
					{
						MoveCursor(0, 1, k.Shift());
					}
					return true;
					break;
				}
				default:
				{
					switch (k.c16)
					{
						case 'x':
						case 'X':
						{
							if (k.Ctrl())
							{
								if (k.Down())
									Cut();
								return true;
							}
							break;
						}
						case 'c':
						case 'C':
						{
							if (k.Ctrl())
							{
								if (k.Down())
									Copy();
								return true;
							}
							break;
						}
						case 'v':
						case 'V':
						{
							if (k.Ctrl())
							{
								if (k.Down())
									Paste();
								return true;
							}
							break;
						}
					}
					break;
				}
			}
		}

		bool Status = GHtml2::OnKey(k);
		LgiAssert(IsOk());
		return Status;
	}

	void SetCursorVis(bool b) { GHtml2::SetCursorVis(b); }
	bool GetCursorVis() { return GHtml2::GetCursorVis(); }

	struct IsOkData
	{
		bool CursorOk;
		bool SelectOk;

		IsOkData()
		{
			CursorOk = false;
			SelectOk = false;
		}
	};

	bool CheckTree(GTag *t, IsOkData &Ok)
	{
		if (t->Parent && !t->Parent->Tags.HasItem(t))
		{
			LgiAssert(!"Tag heirarchy error.");
			return false;
		}

		if (Cursor == t)
		{
			if (t->Cursor < 0)
			{
				LgiAssert(!"Cursor pointer points to tag with no Cursor index.");
				return 0;
			}

			if (t->Text())
			{
				Ok.CursorOk = t->Cursor <= StrlenW(t->Text());
				if (!Ok.CursorOk)
				{
					LgiAssert(!"Cursor index outside length of text.");
				}
			}
			else
				Ok.CursorOk = true;
		}
		else if (t->Cursor >= 0)
		{
			LgiAssert(!"Tag has Cursor index without being pointed at.");
			return false;
		}

		if (Selection == t)
		{
			if (t->Selection < 0)
			{
				LgiAssert(!"Selection pointer points to tag with no Selection index.");
				return 0;
			}

			if (t->Text())
			{
				Ok.SelectOk = t->Selection <= StrlenW(t->Text());
				if (!Ok.SelectOk)
				{
					LgiAssert(!"Selection index outside length of text.");
				}
			}
			else Ok.SelectOk = true;
		}
		else if (t->Selection >= 0)
		{
			LgiAssert(!"Tag has Selection index without being pointed at.");
			return false;
		}

		for (GTag *c=t->Tags.First(); c; c=t->Tags.Next())
		{
			if (!CheckTree(c, Ok))
				return false;
		}

		return true;
	}

	bool IsOk()
	{
		IsOkData Ok;
		if (!CheckTree(Tag, Ok))
			return false;
		if (Cursor && !Ok.CursorOk)
			return false;
		if (Selection && !Ok.SelectOk)
			return false;
		return true;
	}

	GTag *GetTag()
	{
		return Tag;
	}
};
#endif

class GHtmlEditPriv
{
public:
	::HtmlEdit *e;
	bool IgnorePulse;
	GCombo *SelectStyle;
	GCombo *SelectFont;
	GCombo *SelectPtSize;
	GImageList *Icons;
	Btn *IsBold;
	Btn *IsItalic;
	Btn *IsUnderline;

	GHtmlEditPriv()
	{
		e = 0;
		IgnorePulse = 0;
		Icons = 0;
		IsBold = 0;
		IsItalic = 0;
		IsUnderline = 0;
		SelectStyle = 0;
		SelectFont = 0;
		SelectPtSize = 0;
	}

	~GHtmlEditPriv()
	{
		DeleteObj(Icons);
	}

	void PrepareForEdit(GTag *t)
	{
		if
		(
			t->Tag &&
			(
				!stricmp(t->Tag, "b") ||
				!stricmp(t->Tag, "i") ||
				!stricmp(t->Tag, "u")
			)
		)
		{
			t->SetTag("span");
		}

		if (t->TagId == TAG_BR)
		{			
			int Idx = t->Parent->Tags.IndexOf(t);
			GTag *Prev = Idx > 0 ? t->Parent->Tags[Idx-1] : 0;
			if (!Prev || !Prev->Text())
			{
				// Insert empty content tag to allow use to insert text at this point
				GTag *Content = new GTag(t->Html, 0);
				if (Content)
				{
					char16 Empty[] = {0};
					Content->Text(NewStrW(Empty));
					t->Parent->Attach(Content, Idx >= 0 ? Idx : 0);
				}
			}
		}

		List<GTag>::I it = t->Tags.Start();
		for (GTag *c = *it; c; c = *++it)
		{
			PrepareForEdit(c);
		}
	}
};


GHtmlEdit::GHtmlEdit()
{
	d = new GHtmlEditPriv;

	// Setup the toolbar
	Children.Insert(d->SelectStyle = new GCombo(IDC_STYLE, 0, 0, 80, TOOLBAR_HT, 0));
	if (d->SelectStyle)
	{
		d->SelectStyle->SetTabStop(TAB_STOP);
		d->SelectStyle->Insert("Normal");
		d->SelectStyle->Insert("Heading 1");
		d->SelectStyle->Insert("Heading 2");
		d->SelectStyle->Insert("Heading 3");
	}
	Children.Insert(d->SelectFont = new GCombo(IDC_FONT, 0, 0, 80, TOOLBAR_HT, 0));
	if (d->SelectFont)
	{
		d->SelectFont->SetTabStop(TAB_STOP);
		d->SelectFont->Insert("Arial");
		d->SelectFont->Insert("Courier");
		d->SelectFont->Insert("Tahoma");
		d->SelectFont->Insert("Times");
		d->SelectFont->Insert("Verdana");
	}
	Children.Insert(d->SelectPtSize = new GCombo(IDC_POINTSIZE, 0, 0, 60, TOOLBAR_HT, 0));
	if (d->SelectPtSize)
	{
		d->SelectPtSize->SetTabStop(TAB_STOP);
		d->SelectPtSize->Insert("8 pt");
		d->SelectPtSize->Insert("9 pt");
		d->SelectPtSize->Insert("10 pt");
		d->SelectPtSize->Insert("11 pt");
		d->SelectPtSize->Insert("12 pt");
		d->SelectPtSize->Insert("13 pt");
		d->SelectPtSize->Insert("14 pt");
		d->SelectPtSize->Insert("16 pt");
		d->SelectPtSize->Insert("18 pt");
		d->SelectPtSize->Insert("22 pt");
		d->SelectPtSize->Insert("28 pt");
		d->SelectPtSize->Insert("32 pt");
	}	

	d->Icons = new GImageList(16, 16, Icons.Create());
	Children.Insert(d->IsBold = new Btn(IDC_BOLD, 0, true, d->Icons, 24));
	Children.Insert(d->IsItalic = new Btn(IDC_ITALIC, 1, true, d->Icons, 20));
	Children.Insert(d->IsUnderline = new Btn(IDC_UNDERLINE, 2, true, d->Icons, 24));
	Children.Insert(d->e = new ::HtmlEdit(this));

	OnPosChange();
}

GHtmlEdit::~GHtmlEdit()
{
	DeleteObj(d);
}

int GHtmlEdit::OnNotify(GViewI *c, int f)
{
	switch (c->GetId())
	{
		case IDC_BOLD:
		{
			d->IsBold->Value(d->e->OnBold());
			break;
		}
		case IDC_ITALIC:
		{
			d->IsItalic->Value(d->e->OnItalic());
			break;
		}
		case IDC_UNDERLINE:
		{
			d->IsUnderline->Value(d->e->OnUnderline());
			break;
		}
	}

	return GDocView::OnNotify(c, f);
}

void GHtmlEdit::SetIgnorePulse(bool b)
{
	d->IgnorePulse = b;
}

void GHtmlEdit::OnCreate()
{
	OnPosChange();
	AttachChildren();
	if (d->e)
	{
		d->e->Focus(true);
	}
	SetPulse(750);
}

void GHtmlEdit::OnPosChange()
{
	int x = 0;
	int y = 0;
	GRect Client = GetClient();
	if (Client.X() > 16)
	{
		for (GViewI *c = Children.First(); c; c = Children.Next())
		{
			if (c != (GView*)d->e)
			{
				GRect p = c->GetPos();
				p.Offset(x - p.x1, y - p.y1);
				if (x > 0 && p.x2 > Client.x2)
				{
					x = 0;
					y += 20;
					p.Offset(x - p.x1, y - p.y1);
				}
				c->SetPos(p);
				x += p.X();
				if (dynamic_cast<GCombo*>(c))
					x += 8;
			}
		}
	}

	if (d->e)
	{
		GRect c = GetClient();
		c.y1 += y + TOOLBAR_HT + 6;
		if (c.Valid())
		{
			d->e->SetPos(c);
			d->e->Visible(true);
		}
		else
		{
			d->e->Visible(false);
		}
	}
}

void GHtmlEdit::OnPaint(GSurface *pDC)
{
	pDC->Colour(LC_MED, 24);
	pDC->Rectangle();

	/*
	pDC->Colour(Rgb24(255, 0, 0), 24);
	pDC->Box(0, 0, 300, 25);
	*/
}

char *GHtmlEdit::Name()
{
	return d->e->Name();
}

bool GHtmlEdit::Name(char *s)
{
	bool r = d->e->Name(s);
	if (r)
	{
		d->PrepareForEdit(d->e->GetTag());
		d->e->GetCur();
	}

	return r;
}

void GHtmlEdit::OnPulse()
{
	if (d->e->Focus())
	{
		if (!d->IgnorePulse)
		{
			d->e->SetCursorVis(!d->e->GetCursorVis());
		}
	}
	else
	{
		d->e->SetCursorVis(false);
	}

	d->IgnorePulse = false;
}

bool GHtmlEdit::Sunken()
{
	return d->e ? d->e->Sunken() : false;
}

void GHtmlEdit::Sunken(bool i)
{
	if (d->e)
		d->e->Sunken(i);
}

/////////////////////////////////////////////////////////////////////////////////////
class GHtmlEdit_Factory : public GViewFactory
{
	GView *NewView(char *Class, GRect *Pos, char *Text)
	{
		if (stricmp(Class, "GHtmlEdit") == 0)
		{
			return new GHtmlEdit;
		}

		return 0;
	}

} GHtmlEdit_Factory;
